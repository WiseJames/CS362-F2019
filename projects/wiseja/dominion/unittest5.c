#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// assert functionality helped by: dillonbhuff.com/?p=439
#define STR(x) #x
#define MYASSERT(x) if(!(x)) { printf("Assert failed: (%s), function %s, file %s, line %d.\n", STR(x), __PRETTY_FUNCTION__, __FILE__, __LINE__); }

int main (int argc, char** argv) {
	// set card array
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall  };

	// declare the game state
	struct gameState G;
	struct gameState origG;

	int ret = 0; 

	printf("Starting test of mineCardEffect() \n");

	memset(&G, 0, sizeof(struct gameState));	// set the game state
	initializeGame(2, k, 1, &G); 				// init the game
	G.hand[0][1] = 1; 

	ret = mineCardEffect(&G, 0, 1, 1, 1); 
	MYASSERT(ret == -1); 						// test correct card selected error

	
	memset(&G, 0, sizeof(struct gameState));
	initializeGame(2, k, 1, &G); 
	G.hand[0][1] = 5;

	ret = mineCardEffect(&G, 0, 1, -1, 0); 
	MYASSERT(ret == -1); 						// test error msg for choice 2

	
	memset(&G, 0, sizeof(struct gameState)); 
	initializeGame(2, k, 1, &G);
	G.hand[0][1] = 5;
	G.handCount[0] = 1;
	origG = G;

	ret = mineCardEffect(&G, 0, 0, 6, 0); 
	MYASSERT(G.deckCount[0] == origG.deckCount[0]);		// test card gained and discarded

	


	printf("Test Complete\n");
	return 0; 
}
