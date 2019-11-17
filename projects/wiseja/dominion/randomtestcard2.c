#include "dominion.h"
#include "rngs.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
// assert functionality helped by: dillonbhuff.com/?p=439
#define STR(x) #x
#define MYASSERT(x) if (!(x)) {	printf("Assert failed: (%s), function %s, file %s, line %d.\n", STR(x), __PRETTY_FUNCTION__, __FILE__, __LINE__);}

// random test for minion

int main(int argc, char** argv) {
	// set card array
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };

	// declare the game state
	struct gameState G;
	struct gameState origG;
	
	for (size_t i = 0; i < 1000000; i++) {
		// random player count
		int player = floor(Random() * MAX_PLAYERS);


		// set the game state and init
		memset(&G, 0, sizeof(struct gameState));
		initializeGame(player, k, 1, &G);

		// for each player, generate random hand
		for (size_t i = 0; i < player; i++) {
			int randHandSize = floor(Random() * MAX_HAND);

			for (size_t j = 0; j < randHandSize; j++) {
				int randomCard = floor(Random() * 10);
				G.hand[i][j] = k[randomCard];
			}
		}
		
		// save copy of game state
		origG = G;

		int randHandPos = floor(Random() * MAX_HAND);
		int randPlayer = floor(Random() * player);
		int randChoice1 = floor(Random() * 2);
		int randChoice2 = floor(Random() * 2);

		minionCardEffect(&G, randHandPos, randPlayer, randChoice1, randChoice2);

		MYASSERT(G.numActions == origG.numActions + 1);

	}
}


 