CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

unittestbug1: dominion.o unittestbug1.c
	gcc -o unittestbug1 unittestbug1.c -g dominion.o rngs.o $(CFLAGS)

unittestbug2: dominion.o unittestbug2.c
	gcc -o unittestbug2 unittestbug2.c -g dominion.o rngs.o $(CFLAGS)

unittestbug3: dominion.o unittestbug3.c
	gcc -o unittestbug3 unittestbug3.c -g dominion.o rngs.o $(CFLAGS)

unittestbug4: dominion.o unittestbug4.c
	gcc -o unittestbug4 unittestbug4.c -g dominion.o rngs.o $(CFLAGS)

unittestbug8: dominion.o unittestbug8.c
	gcc -o unittestbug8 unittestbug8.c -g dominion.o rngs.o $(CFLAGS)

unittestbug9: dominion.o unittestbug9.c
	gcc -o unittestbug9 unittestbug9.c -g dominion.o rngs.o $(CFLAGS)

unittestbug10: dominion.o unittestbug10.c
	gcc -o unittestbug10 unittestbug10.c -g dominion.o rngs.o $(CFLAGS)



all: playdom player unittestbug1 unittestbug2 unittestbug3 unittestbug4

unittestresults: unittestbug1 unittestbug2 unittestbug3 unittestbug4
	./unittestbug1 &> unittestresults.out
	./unittestbug2 >> unittestresults.out
	./unittestbug3 >> unittestresults.out
	./unittestbug4 >> unittestresults.out
	./unittestbug8 >> unittestresults.out
	./unittestbug9 >> unittestresults.out
	./unittestbug10 >> unittestresults.out
	gcov dominion.c -b -f >> unittestresults.out
	cat dominion.c.gcov >> unittestresults.out


clean:
	rm -f *.o playdom.exe playdom player player.exe unittestbug1 unittestbug2 unittestbug3 unittestbug4 unittestbug8 unittestbug9 unittestbug10 *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
