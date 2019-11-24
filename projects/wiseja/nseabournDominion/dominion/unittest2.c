#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// assert functionality helped by: dillonhugg.com/?p=439
#define STR(x) #x
#define MYASSERT(x) if (!(x)) { printf("Assert failed: (%s), function %s, file %s, line %d.\n", STR(x), __PRETTY_FUNCTION__, __FILE__, __LINE__);}

int minionCardEffect(int choice1, int choice2, struct gameState *state, int handPos, int currentPlayer); 

int main (int argc, char** argv) {

	// set card array 
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };

	// game state
	struct gameState G;
	struct gameState origG;

	printf("Starting test of minionCardEffect() \n"); 
	memset(&G, 0, sizeof(struct gameState)); 	// set game state
	initializeGame(2, k, 1, &G); 				// init game
	origG = G; 									// save copy of game state

	minionCardEffect(1, 1, &G, 1, 0); 

	MYASSERT(G.numActions == origG.numActions + 1); 		// actions incremented by one
	MYASSERT(G.handCount[0] == origG.handCount[0] - 1); 	// player one hand count decremented
	MYASSERT(G.coins == origG.coins + 2); 					// 2 coins added if choice1 = true

	// reset game state
	memset(&G, 0, sizeof(struct gameState));
	initializeGame(2, k, 1, &G); 
	G.handCount[0] = 5; 	
	G.handCount[1] = 5; 
	origG = G; 	

	minionCardEffect(1, 1, &G, 1, 0);

	MYASSERT(G.handCount[0] == 4); 		// the redraw hand count is now four
	MYASSERT(G.handCount[1] == 4); 		// retraw hand count is now four


	printf("Test complete\n"); 
	return 0; 
}
