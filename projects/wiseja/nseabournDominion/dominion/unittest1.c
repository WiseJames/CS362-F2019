#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// assert functionality helped by: dillonbhuff.com/?p=439
#define STR(x) #x
#define MYASSERT(x) if (!(x)) {	printf("Assert failed: (%s), function %s, file %s, line %d.\n", STR(x), __PRETTY_FUNCTION__, __FILE__, __LINE__);}

void baronCardEffect(int choice1, struct gameState *state, int handPos, int currentPlayer);

int main (int argc, char** argv) {

	// set card array
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	
	// declare the game state
	struct gameState G; 
	struct gameState origG; 

	printf("Starting test of baronCardEffect() \n"); 

	memset(&G, 0, sizeof(struct gameState)); 	// set the game state
	initializeGame(2, k, 1, &G); 				// init the game
	G.supplyCount[1] = 5;	// set supply count to 5
	origG = G;									// save a copy of the game state to compare later

	baronCardEffect(1, &G, 1, 1);					// run card effect function
	
	MYASSERT(G.numBuys == origG.numBuys + 1);							// buys incremented by one
	MYASSERT(G.handCount[1] == origG.handCount[1] + 1);					// player 1 +1 estate
	MYASSERT(G.supplyCount[estate] == origG.supplyCount[estate] - 1);	// estate supply -1
	
	//reset game state 
	memset(&G, 0, sizeof(struct gameState)); 
	initializeGame(2, k, 1, &G); 
	G.hand[1][1] = estate; 											// give player one estate card
	origG = G; 

	baronCardEffect(1, &G, 1, 1); 

	MYASSERT(G.coins == origG.coins + 4);							// coins +4
	MYASSERT(G.discardCount[1] == origG.discardCount[1] + 1);		// discard count +1

	// reset game state
	memset(&G, 0, sizeof(struct gameState));
	initializeGame(2, k, 1, &G); 
	G.supplyCount[estate] = 5; 
	origG = G;
	
	baronCardEffect(1, &G, 0, 1); 

	MYASSERT(G.handCount[1] == G.handCount[1] + 1); 				// hand coung +1 estate

	printf("Test complete.\n"); 

	return 0; 
}
