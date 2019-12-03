#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// assert functionality helped by: dillonbhuff.com/?p=439
#define STR(x) #x
#define MYASSERT(x) if (!(x)) {	printf("Assert failed: (%s), function %s, file %s, line %d.\n", STR(x), __PRETTY_FUNCTION__, __FILE__, __LINE__);}

int main(int argc, char** argv) {

	// set card array
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };

	// declare the game state
	struct gameState G;
	struct gameState origG;

	memset(&G, 0, sizeof(struct gameState)); 	// set the game state
	initializeGame(2, k, 1, &G); 				// init the game

	G.hand[0][1] = copper;				// place copper card at position 1

	origG = G;							// save a copy of the game state to compare later

	int choice1 = 1;
	int choice2 = silver;
	int choice3 = 0;
	int handPos = 0;
	int *bonus = 0;

	cardEffect(remodel, choice1, choice2, choice3, &G, handPos, bonus);

	MYASSERT(G.playedCardCount == origG.playedCardCount);

	return 0;
}