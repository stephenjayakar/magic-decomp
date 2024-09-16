import json
import re

# Load the JSON data from the file
with open('input.json', 'r') as file:
    data = json.load(file)

# Extract the rows from the JSON
rows = data['diff_output']['rows']

# Extract assembly code from the base column with line numbers in hexadecimal
assembly_base = []
for row in rows:
    if 'base' in row and 'text' in row['base']:
        line_number = row['base']['line']  # Get line number
        instruction_parts = []
        for text_chunk in row['base']['text']:
            # Append text parts to the instruction parts list
            if 'text' in text_chunk:
                instruction_parts.append(text_chunk['text'])
        # Join all parts to form the full instruction
        full_instruction = ''.join(instruction_parts).strip()

        # Remove the address part and any ~> substrings
        if full_instruction:
            parts = full_instruction.split(maxsplit=1)
            if len(parts) > 1:
                assembly_code = parts[1]
            else:
                assembly_code = parts[0]

            # Remove "~>" substrings
            assembly_code = re.sub(r'~>', '', assembly_code).strip()

            # Combine line number in hex and instruction
            assembly_with_line = f"{line_number:02x}: {assembly_code}"  # Format line number in hex
            assembly_base.append(assembly_with_line)

# Print the assembly instructions
for instruction in assembly_base:
    print(instruction)
