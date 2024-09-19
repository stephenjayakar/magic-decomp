import sys
import os

command = 'MWCIncludes=tmp wine bin/mwcceppc.exe -O4,p -nodefaults -fp hard -Cpp_exceptions off -enum int -fp_contract on -inline auto -c -o build/temp.o'

input_filename = sys.argv[1]
os.system(f'{command} {input_filename}')

os.system('ppc-linux-objdump build/temp.o -d > build/temp.s')
