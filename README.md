# [WIP] How to use this

This is not ready for consumption

* insert in `asm-differ` lib into this folder
* `python3 main.py` with a `inputs/input.s`
* using dtk macros.inc in the `melee` repo. put in `inputs` folder

# Further explorations

Thanks for making it here! It's a shame I don't have infinite time & motivation (and money to train models), or I would probably keep poking at this. Here are the most promising trees to bark up:

### Training `decomp-permuter`

[`decomp-permuter`](https://github.com/simonlindholm/decomp-permuter) is a tool that I've used for a couple of "matches" - it randomly permutes the C code you give it to try to match the ASM perfectly. It runs in parallel and is often really good at getting the match when you've already gotten really close yourself.

I didn't actually spend as much time investigating this tool as I should have, considering that it's very similar to the infrastructure I set up in my project. Namely:
* It generates C code
* It compiles it
* It compares the ASM to the target ASM

Which is pretty much all of the pieces I struggled with. One reason I stayed away from it was because when I used to use the tool locally, I was actually getting different `diff`  results from the tool vs. `decomp.me`. Now that I actually understand how the underlying tools work, it would be great to revisit this project.

Specifically, the thing someone would want to investigate is coming up with a trained version of this permuter to pick specific permutations based on:
* the input C code
* the ASM diff
* the compiler.

There are [some weights](https://github.com/simonlindholm/decomp-permuter/blob/main/default_weights.toml#L44-L50) that appear to be custom for the `mwcc`, which is the MetroWerks C compiler for PowerPC (which is what's used for Melee). This isn't complicated enough though to actually work really fast, both based on experience and my above definition of the inputs I think that are important.

My 2 cents - this feels like this could work really well. It possibly doesn't even have to be a generalized search model; you could overfit to a solution for 1 problem, and then move onto the next. Then, you can prune the starting parameters that work well after observing a couple of C ASM pairs, and then have it start off on a better foot the next time. But I'm not an ML researcher + I still have a lot to learn, so I leave this open.

### Generating a larger training set

Pretty much just title. You can see my small dataset here https://github.com/stephenjayakar/decomp-0-context-training. 

### Try out other models

I did try out `o1-preview`. It was better than `4o`, and it did show a slight ability to iterate. However, it still wasn't able to get to a solution. I decided the runtime was way too high to justify using it.

I didn't try Claude or anything - could be interesting!

