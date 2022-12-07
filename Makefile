CC = gcc
CC_FLAGS = -O0
DEBUG_FLAGS = -g -O0 -Wall -Werror
DEPS = utils.o

all: runner objdumps
all_static: static objdumps

%.o: %.c
	${CC} ${CC_FLAGS} -c $<

runner: utils.o
	$(CC) $(CC_FLAGS) -o runner calories.c $(DEPS)
	./runner input.txt

debug: utils.o
	$(CC) $(DEBUG_FLAGS) -o runner calories.c $(DEPS)
	gdb runner

static:
	${CC} ${CC_FLAGS} --static -c utils.c -o utils.o
	${CC} ${CC_FLAGS} --static -c calories.c -o calories.o
	${CC} ${CC_FLAGS} --static calories.o utils.o -o runner

objdumps: utils.o calories.o runner
	# .text sections
	objdump -d utils.o > utils.od
	objdump -d calories.o > calories.od
	objdump -d runner > runner.od

	# symbol tables
	objdump -t utils.o > utils_symtab.od
	objdump -t calories.o > calories_symtab.od
	objdump -t runner > runner_symtab.od

clean:
	rm runner *.o *.od