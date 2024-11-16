import sys
import subprocess
import os

def try_compile(input_filename: str) -> (bool, str):
    command = [
        'wine', 'bin/mwcceppc.exe', '-O4,p', '-nodefaults', '-fp', 'hard',
        '-Cpp_exceptions', 'off', '-enum', 'int', '-fp_contract', 'on',
        '-inline', 'auto', '-c', '-o', 'outputs/temp.o', input_filename
    ]
    env = os.environ.copy()
    env['MWCIncludes'] = 'tmp'

    # We're capturing stdout / stderr to reduce what's printed
    try:
        subprocess.run(
            command,
            env=env,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            check=True,
        )
    except subprocess.CalledProcessError as e:
        # e.stdout is the actual failure message, e.stderr just says it fails
        return False, e.stdout

    objdump_command = ['ppc-linux-objdump', 'outputs/temp.o', '-d']
    try:
        subprocess.run(
            objdump_command,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            check=True,
        )
    except subprocess.CalledProcessError as e:
        # TODO: not really sure what happens if objdump fails
        print(f"Objdump failed: {e.stderr}")
        return False, e.stderr

    return True, ""


if __name__ == '__main__':
    input_filename = sys.argv[1]
    print(try_compile(input_filename))
