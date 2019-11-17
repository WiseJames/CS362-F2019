#include "dominion.h"
#include "rngs.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// assert functionality helped by: dillonbhuff.com/?p=439
#define STR(x) #x
#define MYASSERT(x) if (!(x)) {	printf("Assert failed: (%s), function %s, file %s, line %d.\n", STR(x), __PRETTY_FUNCTION__, __FILE__, __LINE__);}

// random test for tribute

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
			for (size_t j = 0; j < MAX_HAND; j++) {
				int randomCard = floor(Random() * 10);
				G.hand[i][j] = k[randomCard];
			}
		}

		int newArray[5]; 
		for (size_t i = 0; i < 5; i++) {
			int randomCard = floor(Random() * 10);
			newArray[i] = k[randomCard];
		}

		int randPlayer		= floor(Random() * player);
		int randNextPlayer = floor(Random() * player); 

		// save copy of game state
		origG = G;

		tributeCardEffect(&G, randNextPlayer, newArray, randPlayer); 

		
		MYASSERT(G.deckCount[1] == origG.deckCount[1] - 1); 
		MYASSERT(G.discardCount[1] == origG.discardCount[1] - 1);
		MYASSERT(G.deckCount[1] == origG.deckCount[1] - 1);
		MYASSERT(G.coins == origG.coins + 2);
		MYASSERT(G.numActions == origG.numActions + 2);
	
	}


}

 