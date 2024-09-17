import os
from openai import OpenAI
from dotenv import load_dotenv

# Load environment variables from .env file
load_dotenv()

model = 'gpt-4o-2024-08-06'
openai_client = OpenAI(api_key=os.environ.get("OPENAI_API_KEY"))


def generate_initial_c_code():
    input_file = 'inputs/initial_input.md'
    system_prompt_file = 'initial_system_prompt.txt'
    output_file = 'outputs/initial_output.c'
    generate_c_code(input_file, system_prompt_file, output_file)


def generate_assembly_matched_c_code():
    input_file = 'inputs/assembly_input.md'
    system_prompt_file = 'assembly_system_prompt.txt'
    output_file = 'outputs/assembly_output.c'
    generate_c_code(input_file, system_prompt_file, output_file)


def generate_c_code(input_file, system_prompt_file, output_file):
    # Read the input Markdown file
    with open(input_file, 'r') as file:
        user_message = file.read()

    # Read system prompt
    with open(system_prompt_file, 'r') as file:
        system_prompt = file.read()

    # Create the API request payload
    messages = [
        {"role": "system", "content": system_prompt},
        {"role": "user", "content": user_message}
    ]

    print ('Querying ChatGPT...')
    response = openai_client.chat.completions.create(
        model=model,
        messages=messages
    )

    # Extract the output message
    output_message = response.choices[0].message.content

    # Extract only the C code from the output
    code_start = output_message.find('```c')
    code_end = output_message.rfind('```')

    if code_start != -1 and code_end != -1:
        c_code = output_message[code_start + len('```c'):code_end].strip()
    else:
        c_code = output_message

    # Write the C code to the output file
    with open(output_file, 'w') as file:
        file.write(c_code)

    print(f"The C code has been generated and saved to {output_file}")
