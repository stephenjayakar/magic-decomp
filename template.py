from pathlib import Path

initial_pass_template = Path("prompt-template.md").read_text()
error_template = Path("prompt-template-error.md").read_text()
error_foreach_template = Path("error-foreach.md").read_text()
successful_chain_template = Path("successful-chain.md").read_text()


def _template_gen(template: str, args: dict):
    for key, value in args.items():
        template = template.replace("${" + key + "}", value)
    assert ("$" not in template, "templating didn't replace all values")
    return template


def initial_pass_message(
    asm: str,
    m2c_output: str,
):
    return _template_gen(
        initial_pass_template,
        {
            "ASM": asm,
            "M2C_OUTPUT": m2c_output,
        },
    )


def error_message(
    asm: str,
    c_and_errs: list,
):
    templated_messages = []
    for c, err in c_and_errs:
        templated_messages.append(
            _template_gen(
                error_foreach_template,
                {
                    "C": c,
                    "ERRORS": err,
                },
            )
        )
    return _template_gen(
        error_template,
        {
            "ASM": asm,
            "ERRORS": "\n\n".join(templated_messages),
        },
    )


def successful_chain_message(
    c: str,
    score: int,
    diff_table: str,
):
    score = str(score)
    return _template_gen(
        successful_chain_template,
        {
            "C": c,
            "SCORE": score,
            "DIFF_TABLE": diff_table,
        },
    )
