#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// assert functionality helped by: dillonbhuff.com/?p=439
#define STR(x) #x
#define MYASSERT(x) if (!(x)) { printf("Assert failed: (%s), function %s, file %s, line %d.\n",STR(x), __PRETTY_FUNCTION__, __FILE__, __LINE__); }

int main (int argc, char** argv) {

	// set card array
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall  };

	// declare the game state
	struct gameState G;
	struct gameState origG;

	printf("Starting test of tributeCardEffect() \n");

	memset(&G, 0, sizeof(struct gameState)); 	// set the game state
	initializeGame(2, k, 1, &G); 				// init the game

	int newArray[5] = {1, 2, 3, 4, 5};
	G.discardCount[1] = 0; 
	G.deckCount[1] = 1; 
	origG = G; 

	tributeCardEffect(&G, 1, newArray, 0);
	MYASSERT(G.deckCount[1] == origG.deckCount[1] - 1); 		// test deck count dec

	G.discardCount[1] = 5; 
	G.deckCount[1] = 0; 
	origG = G;

	int newArray2[5] = {1, 2, 3, 4, 5};
	tributeCardEffect(&G, 1, newArray2, 0); 
	MYASSERT(G.discardCount[1] == origG.discardCount[1] - 1); 	// test discard count dec

	memset(&G, 0, sizeof(struct gameState)); 
	initializeGame(3, k, 1, &G); 
	G.discardCount[1] = 0; 
	G.deckCount[1] = 5; 

	origG = G; 

	int newArray3[5] = {16, 2, 3, 4, 5}; 
	tributeCardEffect(&G, 1, newArray3, 0); 

	MYASSERT(G.deckCount[1] == origG.deckCount[1] - 1);
	MYASSERT(G.coins == origG.coins + 2); 
	MYASSERT(G.numActions == origG.numActions + 2);

	printf("Test Complete.\n");
	return 0; 
}
