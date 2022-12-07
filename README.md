#Hey all!

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












#Good luck! -Zach
