import re

input_declarations = """
extern s32 Fighter_804D64FC;
extern s32 Fighter_804D6500;
extern s32 Fighter_804D6504;
extern s32 Fighter_804D6508;
extern s32 Fighter_804D650C;
extern s32 Fighter_804D6510;
extern s32 Fighter_804D6514;
extern s32 Fighter_804D6518;
extern s32 Fighter_804D651C;
extern s32 Fighter_804D6520;
extern s32 Fighter_804D6524;
extern s32 Fighter_804D6528;
extern s32 Fighter_804D652C;
extern s32 Fighter_804D6530;
extern s32 Fighter_804D6534;
extern s32 Fighter_804D6538;
extern s32 Fighter_804D653C;
extern s32 Fighter_804D6540;
extern s32 Fighter_804D6548;
extern s32 Fighter_804D654C;
extern int** Fighter_804D6550;
extern s32 ftPartsTable;
"""

# Convert the input declarations into a list of variables to search for
variables_to_find = [line.split()[-1].strip(';') for line in input_declarations.strip().split('\n')]

# Create a pattern to match the variable definitions in the file
pattern = re.compile(r"\b(" + r"|".join(variables_to_find) + r")\b\s*=\s*.*;")

found_declarations = []

# Read the file and find all matching definitions
with open("one-example.c", "r") as file:
    lines = file.readlines()
    for line in lines:
        if pattern.search(line):
            found_declarations.append(line.strip())

# Print all found declarations as extern
for declaration in found_declarations:
    extern_declaration = "extern " + declaration.split('=')[0].strip() + ";"
    print(extern_declaration)
