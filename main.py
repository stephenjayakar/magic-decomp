import os
from openai import OpenAI
from dotenv import load_dotenv
from halo import Halo
import argparse
from pathlib import Path
from collections import namedtuple

from diff_wrapper import diff_asm
from compile import try_compile
import template

OPENAI_MODEL = "gpt-4o-2024-08-06"
ASM_FILENAME = "inputs/input.s"
M2C_OUTPUT_FILENAME = "outputs/m2c-output.c"

# Load environment variables from .env file
load_dotenv()

openai_client = OpenAI(
    api_key=os.environ.get("OPENAI_API_KEY"),
)


system_prompt = Path("system.txt").read_text()
asm = Path(ASM_FILENAME).read_text()


# We need this for the asm differ, as it doesn't just diff the whole file.
def get_first_function_asm(asm):
    first_fn_index = asm.find(".fn")
    slc = asm[first_fn_index + len(".fn ") :]
    fn_name_end_index = slc.find(",")
    return slc[:fn_name_end_index]


first_function_name = get_first_function_asm(asm)


def extract_c_from_openai_response(response):
    # Extract the output message
    output_message = response.choices[0].message.content

    # Extract only the C code from the output (assuming that the output is clean and directly usable)
    # This part can be adjusted based on the specific format of the output.
    code_start = output_message.find("```c")
    code_end = output_message.rfind("```")

    if code_start != -1 and code_end != -1:
        c_code = output_message[code_start + len("```c") : code_end].strip()
    else:
        c_code = output_message
    return c_code


def query_chatgpt(system_message, user_message, console_message, filename_pass: int):
    with open(f"outputs/tmp-message-{filename_pass}.md", "w") as msg_file:
        msg_file.write(user_message)
    messages = [
        {"role": "system", "content": system_message},
        {"role": "user", "content": user_message},
    ]
    with Halo(text=console_message, spinner="dots"):
        response = openai_client.chat.completions.create(
            model=OPENAI_MODEL, messages=messages
        )
    return response


def initial_pass():
    # TODO(sjayakar): not sure if this is the best place to open the file
    with open(M2C_OUTPUT_FILENAME, "r") as m2c_file:
        m2c_output = m2c_file.read()

    user_message = template.initial_pass_message(asm, m2c_output)

    response = query_chatgpt(
        system_prompt, user_message, "Querying ChatGPT for the first .c file...", 0
    )

    c_code = extract_c_from_openai_response(response)

    write_c_file(0, c_code)


def write_c_file(pass_number, c_code):
    # Write the C code to the output file
    with open(f"outputs/output-{pass_number}.c", "w") as file:
        file.write(c_code)
    print(f"The C code has been generated and saved to outputs/output-{pass_number}.c.")


def clean():
    os.system("rm outputs/*")
    print("Removed all files in output directory")


# TODO(sjayakar): this is silly on multiple levels. i read more and
# more files based on # of passes, and I could have just held it in
# memory 😭.
def fix_compiler_errors(state):
    # TODO: read all sources & error messages
    c_and_errs = []
    for attempt in state.attempts:
        c_and_errs.append((attempt.c_code, attempt.errors))
    user_message = template.error_message(asm, c_and_errs)
    with open(f"outputs/tmp-message-{state.filename_counter}.md", "w") as msg_file:
        msg_file.write(user_message)

    response = query_chatgpt(
        system_prompt,
        user_message,
        "Querying ChatGPT to fix compiler errors",
        state.filename_counter,
    )

    c_code = extract_c_from_openai_response(response)
    write_c_file(state.filename_counter, c_code)


# Attempt to improve the score
def successful_chain(state):
    candidate_messages = "\n".join(
        [
            template.successful_chain_message(c.c_code, c.score, c.diff)
            for c in state.candidates
        ]
    )

    initial_message = template.initial_pass_message(asm, state.m2c)
    message = f"{initial_message}\n{candidate_messages}"
    response = query_chatgpt(
        system_prompt,
        message,
        "Querying ChatGPT to improve the ASM score",
        state.filename_counter,
    )

    c_code = extract_c_from_openai_response(response)
    write_c_file(state.filename_counter, c_code)


# Convert .s to .o for eventually comparing output.o files
def assemble_base():
    print("Assembling the .s file to get expected.o")
    os.system(f"bin/powerpc-eabi-as -I inputs {ASM_FILENAME}")
    os.system("mv a.out outputs/expected.o")
    if not os.path.exists("outputs/expected.o"):
        raise FileNotFoundError("failed to assemble")


# Get the default output of m2c to help ground the ChatGPT response
def m2c():
    print("Running m2c...")
    os.system(
        f"python3 ../m2c/m2c.py --target ppc-mwcc-c {ASM_FILENAME} > {M2C_OUTPUT_FILENAME}"
    )
    if not os.path.exists(M2C_OUTPUT_FILENAME):
        raise FileNotFoundError("m2c failed")


def compile_and_log_error(base_name):
    with Halo(
        text=f"Compiling",
        spinner="dots",
    ):
        compiled_successfully, message = try_compile(f"outputs/{base_name}.c")
    if not compiled_successfully:
        with open(f"outputs/{base_name}.error", "w") as error_file:
            error_file.write(message)
    return compiled_successfully


def parse_args():
    parser = argparse.ArgumentParser(description="AI decompilation script")

    parser.add_argument(
        "--diff-only",
        action="store_true",
        help="Skip generation and just diff with expected",
    )

    args = parser.parse_args()
    return args


# Candidate means "code that compiles and has an ASM diff"
Candidate = namedtuple("NamedTuple", ["c_code", "diff", "score"])

# An attempt is C code & compiler errors
Attempt = namedtuple("Attempt", ["c_code", "errors"])


# State machine with metadata. The program is either improving on the
# ASM diff result or it's attempting to fix compiler errors.
class State:
    def __init__(self):
        # Stuff that's always set
        self.state = STATE_INITIAL
        self.filename_counter = 0
        # Read in all the other stuff
        with open(M2C_OUTPUT_FILENAME, "r") as m2c_file:
            self.m2c = m2c_file.read()
        with open("outputs/output-0.c", "r") as initial_pass_file:
            self.initial_pass = initial_pass_file.read()

        self.candidates = []

    def current_filename_prefix(self):
        return f"output-{self.filename_counter}"

    def _to_err(self, filename_prefix):
        self.state = STATE_ERRORS
        self.attempts = []

    def add_err(self, filename_prefix):
        if self.state != STATE_ERRORS:
            self._to_err()
        with open(f"outputs/{filename_prefix}.c", "r") as c_file:
            c_code = c_file.read()
        with open(f"outputs/{filename_prefix}.error", "r") as err_file:
            errs = err_file.read()
        self.attempts.append(Attempt(c_code, errs))

    def _to_candidate(self, filename_prefix):
        self.state = STATE_CANDIDATE

    def add_candidate(self, filename_prefix):
        if self.state != STATE_CANDIDATE:
            self._to_candidate()
        # TODO: assumes that the candidate was the last compiled code. Yikes!
        with open(f"outputs/{filename_prefix}.c", "r") as c_file:
            c_code = c_file.read()
        diff_output, score = diff_asm(first_function_name)
        self.candidates.append(Candidate(c_code, diff_output, score))


STATE_INITIAL = "INITIAL"
STATE_ERRORS = "ERRORS"
STATE_CANDIDATE = "CANDIDATE"


def main():
    args = parse_args()
    if args.diff_only:
        diff_output, score = diff_asm(first_function_name)
        print(f"ASM Score: {score}")
        print(diff_output)
        return
    clean()
    assemble_base()
    m2c()

    initial_pass()
    prefix = "output-0"
    compiled_successfully = compile_and_log_error(prefix)
    state = State()
    if compiled_successfully:
        state.add_candidate(prefix)
    else:
        state.add_err(prefix)

    while True:
        state.filename_counter += 1
        filename_prefix = state.current_filename_prefix()
        if state.state == STATE_ERRORS:
            print(f"❌ Did not compile, starting compile pass {state.filename_counter}")
            fix_compiler_errors(state)
        elif state.state == STATE_CANDIDATE:
            last_candidate = state.candidates[-1]
            print(
                f"✅ Code compiled. Current ASM score: {last_candidate.score}. Attempting to improve"
            )
            successful_chain(state)
        else:
            raise Exception(f"invalid state {state}")

        # By now, the new C file has been written to disk. Attempt to
        # compile it and then possibly state transition.
        compiled_successfully = compile_and_log_error(filename_prefix)
        if compiled_successfully:
            state.add_candidate(filename_prefix)
        else:
            state.add_err(filename_prefix)


if __name__ == "__main__":
    main()
