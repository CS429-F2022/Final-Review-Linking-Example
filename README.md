# Hey all!

This is a short linking example I set up for the final review.

It uses the solution to day 1 of this year's Advent of Code (https://adventofcode.com/2022/day/1)
to demonstrate how different symbols are used in ELF files.

To give some background to the problem, we are given a list of integers ("calories", hence the name) in `input.txt`,
with blank lines separating them into groups.
We want to find which group has the highest sum in part 1,
and which 3 groups have the highest sums in part 2.
I already solved the problem and guarantee that it works,
but this should give some insight to what the code is doing.

To note, there are several make targets you can use - namely `make all` and `make all_static`
for linking the program either dynamically or statically.
These targets compile the code and run it - though you don't need to care about the answers -
and it creates objdump files for each module as well.


# Activity 1 - ELF Files and Sections

This section explores how symbols are assigned to sections of the ELF file.
This mimics some of the questions we've asked on previous exams, and may be similar to ones
you'll see on Thursday as well.

To start, just type `make all` to compile the source files.
The objdump files will be created as well, but they're mostly for you to check your answer at this point.
Try to answer these without looking at them.

For each of the following symbols in `calories.c`, answer these questions:
- What kind of symbol is it? (Local, Global, External)
- Is it located in the symbol table for `calories.o`?
- If so, which section is it in? 

1. printbuf
2. buf_size
3. data
4. len
5. idx (declared on line 14)
6. part1
7. read_data
8. atoi

Once you're done, we'll reconvene and discuss the answers.

# Activity 2 - Relocation Records

This section takes a look at symbol relocation.
We want to see how symbols changed

For the same symbols as before, answer these questions:
- Does it have a relocation record attached/will references to it require patching?
- If yes, which section of the ELF file is the record in?

1. printbuf
2. buf_size
3. data
4. len
5. idx (declared on line 14)
6. part1
7. read_data
8. atoi

Once you're done, we'll meet up and discuss again.

# Activity 3 - Dynamic Linking

So far, we've looked at things that are the same for both static and dynamic linking.
Now, we'll focus on dynamic linking.

- Which of the following symbols have entries in the dynamic symbol table?

1. printbuf
2. printf
3. atoi
4. data

For fun, type `make clean; make all_static` and look at `runner.od` again.
This links the program statically instead of dynamically.
Makes you appreciate dynamic linking, huh?

# Good luck! -Zach
