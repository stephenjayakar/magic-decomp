import os
from openai import OpenAI
from dotenv import load_dotenv
from halo import Halo
import argparse

from diff_wrapper import diff_asm
from compile import try_compile

OPENAI_MODEL = "gpt-4o-2024-08-06"
ASM_FILENAME = "inputs/input.s"
M2C_OUTPUT_FILENAME = "outputs/m2c-output.c"

# Load environment variables from .env file
load_dotenv()

openai_client = OpenAI(
    api_key=os.environ.get("OPENAI_API_KEY"),
)

# Get all the initial file opening out of the way
with open("system.txt", "r") as file:
    system_prompt = file.read()
with open(ASM_FILENAME, "r") as asm_file:
    asm = asm_file.read()
with open("prompt-template.md", "r") as template_file:
    initial_pass_template = template_file.read()
with open("prompt-template-error.md", "r") as template_file:
    error_template = template_file.read()
with open("error-foreach.md", "r") as template_file:
    error_foreach_template = template_file.read()
with open("successful-chain.md", "r") as template_file:
    successful_chain_template = template_file.read()


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


def query_chatgpt(system_message, user_message, console_message):
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

    user_message = initial_pass_template.replace("${ASM}", asm)
    user_message = user_message.replace("${M2C_OUTPUT}", m2c_output)

    response = query_chatgpt(
        system_prompt, user_message, "Querying ChatGPT for the first .c file..."
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
def fix_compiler_errors(current_compile_passes: int):
    # TODO: read all sources & error messages
    templated_messages = []
    for i in range(current_compile_passes):
        with open(f"outputs/output-{i}.c", "r") as c_file:
            c = c_file.read()
        with open(f"outputs/output-{i}.error", "r") as err_file:
            err = err_file.read()
        message = error_foreach_template.replace("${C}", c)
        message = message.replace("${ERRORS}", err)
        templated_messages.append(message)
    user_message = error_template.replace("${ASM}", asm)
    user_message = user_message.replace("${ERRORS}", "\n\n".join(templated_messages))
    with open(f"outputs/tmp-message-{current_compile_passes}.md", "w") as msg_file:
        msg_file.write(user_message)

    response = query_chatgpt(
        system_prompt, user_message, "Querying ChatGPT to fix compiler errors"
    )

    c_code = extract_c_from_openai_response(response)
    write_c_file(current_compile_passes, c_code)


# Convert .s to .o for eventually comparing output.o files
def assemble_base():
    print("Assembling the .s file to get expected.o")
    os.system("bin/powerpc-eabi-as -I inputs inputs/input.s")
    os.system("mv a.out outputs/expected.o")
    if not os.path.exists("outputs/expected.o"):
        raise FileNotFoundError("failed to assemble")


# Get the default output of m2c to help ground the ChatGPT response
def m2c():
    print("Running m2c...")
    os.system(
        f"python3 ../m2c/m2c.py --target ppc-mwcc-c inputs/input.s > {M2C_OUTPUT_FILENAME}"
    )
    if not os.path.exists("outputs/m2c-output.c"):
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


def main():
    args = parse_args()
    if args.diff_only:
        diff_output, score = diff_asm()
        print(f"ASM Score: {score}")
        # TODO(sjayakar): move chain to end
        # need c code, m2c output, and more
        # successful_chain = successful_chain_template.replace(
        return
    clean()
    assemble_base()
    m2c()
    initial_pass()

    compiled_successfully = compile_and_log_error("output-0")
    compile_passes = 0
    while not compiled_successfully:
        compile_passes += 1
        print(f"❌ Did not compile, starting compile pass {compile_passes}")
        fix_compiler_errors(compile_passes)

        compiled_successfully = compile_and_log_error(f"output-{compile_passes}")
    # TODO(sjayakar): successful compile should have generated temp.o. consider refactoring to generate an overrideable output

    diff_asm()


if __name__ == "__main__":
    main()
