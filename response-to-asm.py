import json
import re

def extract_assembly(data, key):
    """
    Extract assembly instructions from the JSON data based on the specified key ('base' or 'current').

    Args:
        data (dict): JSON data.
        key (str): Key to extract the assembly from ('base' or 'current').

    Returns:
        list: A list of formatted assembly instructions with hexadecimal line numbers.
    """
    rows = data['diff_output']['rows']
    assembly_instructions = []
    
    for row in rows:
        if key in row and 'text' in row[key] and 'line' in row[key]:
            line_number = row[key]['line']  # Get line number
            instruction_parts = []
            
            for text_chunk in row[key]['text']:
                # Append text parts to the instruction parts list, excluding '>' characters.
                if 'text' in text_chunk:
                    cleaned_text = text_chunk['text'].replace('>', '').replace('~', '').strip()
                    instruction_parts.append(cleaned_text)

            # Join all parts to form the full instruction
            full_instruction = ' '.join(instruction_parts).strip()
            
            # Remove the address part
            parts = full_instruction.split(maxsplit=1)
            if len(parts) > 1:
                assembly_code = parts[1]
            else:
                assembly_code = parts[0]

            # Combine line number in hex and instruction
            assembly_with_line = f"{line_number:04x}: {assembly_code}"  # Format line number in hex with padding
            assembly_instructions.append(assembly_with_line)

    return assembly_instructions

def extract_target_asm(json_file):
    """
    Extract the target assembly instructions.

    Args:
        json_file (str): Path to the JSON file.

    Returns:
        list: A list of formatted target assembly instructions.
    """
    with open(json_file, 'r') as file:
        data = json.load(file)
    return extract_assembly(data, 'base')

def extract_generated_asm(json_file):
    """
    Extract the generated assembly instructions.

    Args:
        json_file (str): Path to the JSON file.

    Returns:
        list: A list of formatted generated assembly instructions.
    """
    with open(json_file, 'r') as file:
        data = json.load(file)
    return extract_assembly(data, 'current')

if __name__ == "__main__":
    import argparse

    # Argument parser for command-line execution
    parser = argparse.ArgumentParser(description="Extract target or generated assembly instructions from a JSON file.")
    parser.add_argument('json_file', help="Path to the JSON file")
    parser.add_argument('type', choices=['target', 'generated'], help="Type of assembly to extract ('target' or 'generated')")

    args = parser.parse_args()

    if args.type == 'target':
        instructions = extract_target_asm(args.json_file)
    else:
        instructions = extract_generated_asm(args.json_file)

    # Print the extracted assembly instructions
    for instruction in instructions:
        print(instruction)
