CFLAGS=-Wall -Wextra -pedantic -Ofast -Wshadow 
CC=clang
OBJS=test.o 

test	: $(OBJS)

clean	:
	rm -fr $(OBJS) testset infer-out

infer	:
	make clean; infer-capture -- make; infer-analyze -- make
