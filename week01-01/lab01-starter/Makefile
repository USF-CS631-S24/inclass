# PROGS defines a list of each program to be generated
PROGS = scan1 scan2

# For each PROG we list all the required object files
SCAN1_OBJS = scan1.o
SCAN2_OBJS = scan2.o

# Pattern rule to assemble .s files into .o files
%.o: %.s
	as -g -o $@ $<

# Pattern rule to compile .c files into .o files
%.o: %.c
	gcc -c -g -o $@ $<

# First real rule that will initiate the build of all PROGS
all : $(PROGS)

scan1 : $(SCAN1_OBJS)
	gcc -g -o $@ $^
		
scan2 : $(SCAN2_OBJS)
	gcc -g -o $@ $^

clean :
	rm -f $(PROGS) $(SCAN1_OBJS) $(SCAN2_OBJS)

.PHONY: clean
