import os
from openai import OpenAI
from dotenv import load_dotenv

from compile import try_compile

OPENAI_MODEL = 'gpt-4o-2024-08-06'
ASM_FILENAME = 'inputs/input.s'

# Load environment variables from .env file
load_dotenv()

openai_client = OpenAI(
    api_key=os.environ.get("OPENAI_API_KEY"),
)

# Get all the initial file opening out of the way
with open('system.txt', 'r') as file:
    system_prompt = file.read()
with open(ASM_FILENAME, 'r') as asm_file:
    asm = asm_file.read()
with open('prompt-template.md', 'r') as template_file:
    initial_pass_template = template_file.read()
with open('prompt-template-error.md', 'r') as template_file:
    error_template = template_file.read()

def extract_c_from_openai_response(response):
    # Extract the output message
    output_message = response.choices[0].message.content

    # Extract only the C code from the output (assuming that the output is clean and directly usable)
    # This part can be adjusted based on the specific format of the output.
    code_start = output_message.find('```c')
    code_end = output_message.rfind('```')

    if code_start != -1 and code_end != -1:
        c_code = output_message[code_start + len('```c'):code_end].strip()
    else:
        c_code = output_message
    return c_code

def initial_pass():
    print('Querying ChatGPT for the first .c file...')
    user_message = initial_pass_template.replace("${ASM}", asm)

    # TODO: figure out the right abstraction with openai messages
    messages = [
        {"role": "system", "content": system_prompt},
        {"role": "user", "content": user_message}
    ]

    response = openai_client.chat.completions.create(model=OPENAI_MODEL,
    messages=messages)

    c_code = extract_c_from_openai_response(response)

    write_c_file(0, c_code)

def write_c_file(pass_number, c_code):
    # Write the C code to the output file
    with open(f'outputs/output-{pass_number}.c', 'w') as file:
        file.write(c_code)
    print(f"The C code has been generated and saved to outputs/output-{pass_number}.c.")

def clean():
    os.system('rm outputs/*')
    print('Removed all files in output directory')


# TODO: for now we're just passing in the last error message & file. we can actually have a train of these
def fix_compiler_errors(current_compile_passes: int, last_error_message: str):
    previous_filename = f'outputs/output-{current_compile_passes - 1}.c'
    with open(previous_filename, 'r') as previous_c_file:
        old_c_code = previous_c_file.read()
    user_message = error_template.replace("${ASM}", asm)
    user_message = user_message.replace('${C}', old_c_code)
    user_message = user_message.replace('${ERRORS}', last_error_message)

    # TODO: figure out the right abstraction with openai messages
    messages = [
        {"role": "system", "content": system_prompt},
        {"role": "user", "content": user_message}
    ]

    response = openai_client.chat.completions.create(model=OPENAI_MODEL,
    messages=messages)

    c_code = extract_c_from_openai_response(response)
    write_c_file(current_compile_passes, c_code)

def diff_asm(successful_pass: int):
    os.system(f'cp outputs/temp.o asm-differ/main.o')
    os.system(f'cp outputs/expected.o asm-differ/expected/main.o')
    # TODO(sjayakar): figure out how to get `f1`
    os.system('cd asm-differ && python3 diff.py -o -f main.o f1')

# Convert .s to .o for eventually comparing output.o files
def assemble_base():
    print('Assembling the .s file to get expected.o')
    os.system(f'bin/powerpc-eabi-as -I inputs inputs/input.s')
    os.system('mv a.out outputs/expected.o')
    if not os.path.exists('outputs/expected.o'):
        raise FileNotFoundError("failed to assemble")

def main():
    clean()
    assemble_base()
    initial_pass()

    compiled_successfully, message = try_compile('outputs/output-0.c')
    compile_passes = 0
    while not compiled_successfully:
        compile_passes += 1
        print(f'starting compile pass {compile_passes}, last error message: {message}')
        fix_compiler_errors(compile_passes, message)

        compiled_successfully, message = try_compile(f'outputs/output-{compile_passes}.c')
    successful_pass = compile_passes
    # TODO(sjayakar): successful compile should have generated temp.o. consider refactoring to generate an overrideable output

    diff_asm(successful_pass) # should just print the score



if __name__ == '__main__':
    main()
