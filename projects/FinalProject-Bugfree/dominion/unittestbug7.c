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
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, sea_hag };

	// declare the game state
	struct gameState G;

	memset(&G, 0, sizeof(struct gameState)); 	// set the game state
	initializeGame(2, k, 1, &G); 				// init the game

	G.handCount[G.whoseTurn] = 1;
	G.hand[G.whoseTurn][0] = tribute;
	int nextPlayer = G.whoseTurn + 1;
	if(nextPlayer >= G.numPlayers)
		nextPlayer = 0;
	G.deckCount[nextPlayer] = 3;
	G.deck[nextPlayer][2] = tribute;
	G.deck[nextPlayer][1] = copper;
	G.deck[nextPlayer][0] = estate;
	int coins = G.coins + 2;
	int actions = G.numActions + 2;
	int handsize = G.handCount[G.whoseTurn] - 1;

	cardEffect(tribute, 0, 0, 0, &G, 0, 0);

	MYASSERT(G.coins == coins && G.numActions == actions && G.handCount[G.whoseTurn] == handsize);

	return 0;
}