all: main

main: testme.c
	gcc -g -ftest-coverage -fprofile-arcs testme.c
	./a.out
clean:
	rm -f a.out main.o testme.c.gcov testme.gcda testme.gcno

