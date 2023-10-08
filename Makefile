# This file is a makefile of datastructure

CC = gcc
RM = rm -f
CFLAGS += -std=c11
CFLAGS += -Wall -Wpedantic
LDFLAST += -lm
TARGETS = single_linklist.out double_linklist.out cycle_linklist.out \
	linear_stack.out link_stack.out

all: $(TARGETS)

single_linklist.out: single_linklist.c global.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

double_linklist.out: double_linklist.c global.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

cycle_linklist.out: cycle_linklist.c global.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

linear_stack.out: linear_stack.c global.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

link_stack.out: link_stack.c global.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

global.o: global.c
	$(CC) $(CFLAGS) $(LDFLAGS) -c $^

clean:
	$(RM) -rf $(prog) *.o $(TARGETS)
