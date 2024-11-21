from pathlib import Path

initial_pass_template = Path("prompt-template.md").read_text()
error_template = Path("prompt-template-error.md").read_text()
error_foreach_template = Path("error-foreach.md").read_text()
successful_chain_template = Path("successful-chain.md").read_text()


def _template_gen(template: str, args: dict):
    for key, value in args.items():
        template = template.replace(key, value)
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
    message = initial_pass_template.replace("${ASM}", asm)
    message = message.replace("${M2C_OUTPUT}", m2c_output)
    return message
