import os
from asm_differ import diff

os.chdir("asm_differ")

START = "f1"
FILENAME = "main.o"

default_source_old_binutils = False
default_diff_section = ".text"
default_inlines = False
default_max_lines = 1024
default_skip_lines = 0
default_show_rodata_refs = True
default_show_branches = True
default_show_line_numbers = None
default_show_source = False
default_stop_at_ret = None
default_ignore_large_imms = False
default_ignore_addr_diffs = False
default_algorithm = "levenshtein"
default_diff_function_symbols = False

project = diff.create_project_settings(
    {
        "source_directories": ".",
        "arch": "ppc",
        "build_dir": ".",
        "expected_dir": "expected/",
        "objdump_executable": "ppc-linux-objdump",
    }
)

config = diff.Config(
    arch=diff.PPC_SETTINGS,
    diff_obj=True,
    file=FILENAME,
    make=False,
    source_old_binutils=default_source_old_binutils
    or "llvm-" in project.objdump_executable,
    diff_section=default_diff_section,
    inlines=default_inlines,
    max_function_size_lines=default_max_lines,
    max_function_size_bytes=default_max_lines * 4,
    formatter=diff.PlainFormatter(column_width=50),
    diff_mode=diff.DiffMode.NORMAL,
    base_shift=0,
    skip_lines=default_skip_lines,
    compress=None,  # Assuming no compression required
    show_rodata_refs=default_show_rodata_refs,
    show_branches=default_show_branches,
    show_line_numbers=default_show_line_numbers,
    show_source=default_show_source or default_source_old_binutils,
    stop_at_ret=default_stop_at_ret,
    ignore_large_imms=default_ignore_large_imms,
    ignore_addr_diffs=default_ignore_addr_diffs,
    algorithm=default_algorithm,
    reg_categories={},
    diff_function_symbols=default_diff_function_symbols,
)


def diff_asm():
    os.system("cp outputs/temp.o asm_differ/main.o")
    os.system("cp outputs/expected.o asm_differ/expected/main.o")
    make_target, basecmd, mycmd = diff.dump_objfile(START, None, config, project)
    basedump = diff.run_objdump(basecmd, config, project)
    mydump = diff.run_objdump(mycmd, config, project)

    display = diff.Display(basedump, mydump, config)
    display.run_sync()

    # # TODO(sjayakar): figure out how to get `f1`
    # os.system("cd asm-differ && python3 diff.py -o -f main.o f1")


if __name__ == "__main__":
    diff_asm()
