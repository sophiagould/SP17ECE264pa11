FLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror -Wunreachable-code
COVFLAGS = -fprofile-arcs -ftest-coverage
GCC = gcc $(FLAGS) $(COVFLAGS)
OBJ = pa11.o funcs.o

all: $(OBJ)
	$(GCC) $(OBJ) -o pa11

funcs.o: funcs.c
		$(GCC) -c funcs.c -o funcs.o 

pa11.o: pa11.c pa11.h
		$(GCC) -c pa11.c -o pa11.o

test: all
	./pa11 inputs/test1
	./pa11 inputs/test2
	./pa11 inputs/test3
	./pa11 inputs/test4
	./pa11 inputs/test5

memory: pa11
	valgrind --leak-check=full --show-reachable=yes -v ./pa11 inputs/test1
	valgrind --leak-check=full --show-reachable=yes -v ./pa11 inputs/test2
	valgrind --leak-check=full --show-reachable=yes -v ./pa11 inputs/test3
	valgrind --leak-check=full --show-reachable=yes -v ./pa11 inputs/test4
	valgrind --leak-check=full --show-reachable=yes -v ./pa11 inputs/test5


clean:
	rm -f *.o
	rm -f funcs.gcno
	rm -f funcs.gcda
	rm -f pa11.gcno
	rm -f pa11.gcda
	rm -f pa11
