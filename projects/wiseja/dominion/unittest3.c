#include "dominion.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// assert functionality helped by : dillonbhuff.com/?p=439
#define STR(x) #x
#define MYASSERT(x) if (!(x)) { printf("Assert failed: (%s), function %s, file %s, line %d.\n", STR(x), __PRETTY_FUNCTION__, __FILE__, __LINE__);}

int main (int argc, char** argv) {

	// set card array
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall  };
	
	// declare the game state
	struct gameState G;

	printf("Starting test of ambassadorCardEffect() \n"); 

	memset(&G, 0, sizeof(struct gameState)); 	// set the game state
	initializeGame(2, k, 1, &G); 				// init the game

	int i = ambassadorCardEffect(1, -1, 0 , &G, 1); 
	MYASSERT(i == -1); 
	i = 0; 

	memset(&G, 0, sizeof(struct gameState)); 
	initializeGame(2, k, 1, &G); 
	i = ambassadorCardEffect(1, 0, 1, &G, 0);
	MYASSERT(i == -1);

	memset(&G, 0, sizeof(struct gameState)); 
	initializeGame(2, k, 1, &G); 
	G.handCount[0] = 5; 

	ambassadorCardEffect(1, 2, 0, &G, 0); 
	MYASSERT(i == -1); 

	printf("Test complete \n"); 
	return 0; 
}
