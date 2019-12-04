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

	G.discardCount[G.whoseTurn] = 0;
	G.handCount[G.whoseTurn] = 0;
	G.deckCount[G.whoseTurn] =1;

	int score = 0;

	for(int i=0; i<G.deckCount[G.whoseTurn]; i++){
		G.deck[G.whoseTurn][i] = estate;
		score++;
	}

	MYASSERT(scoreFor(G.whoseTurn, &G) == score);

	return 0;
}