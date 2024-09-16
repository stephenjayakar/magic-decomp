model = 'gpt-4o-2024-08-06'


import os
import openai
from dotenv import load_dotenv

# Load environment variables from .env file
load_dotenv()

# Get the secret key from environment variable
openai.api_key = os.getenv('OPENAI_API_KEY')

# Read the input Markdown file
with open('input.md', 'r') as file:
    user_message = file.read()
# Read system prompt
with open('system.txt', 'r') as file:
    system_prompt = file.read()

# Create the API request payload
messages = [
    {"role": "system", "content": system_prompt},
    {"role": "user", "content": user_message}
]

response = openai.ChatCompletion.create(
    model=model,
    messages=messages,
)

# Extract the output message
output_message = response.choices[0].message['content']

# Extract only the C code from the output (assuming that the output is clean and directly usable)
# This part can be adjusted based on the specific format of the output.
code_start = output_message.find('```c')
code_end = output_message.rfind('```')

if code_start != -1 and code_end != -1:
    c_code = output_message[code_start + len('```c'):code_end].strip()
else:
    c_code = output_message

# Write the C code to the output file
with open('output.c', 'w') as file:
    file.write(c_code)

print("The C code has been generated and saved to output.c.")
