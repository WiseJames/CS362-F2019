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
	int i;

	struct gameState* state = newGame();
	state->numPlayers = 2;
	state->whoseTurn = 0;
	state->numActions = 0;
	state->coins = 0;
	state->numBuys = 0;
	state->handCount[0] = 1;
	state->hand[0][0] = tribute;
	state->deckCount[0] = 60;
	for(i = 0; i < 60; i++){
		state->deck[0][i] = estate;
	}
	state->deckCount[1] = 2;
	state->deck[1][0] = estate;
	state->deck[1][1] = estate;
	state->playedCardCount = 0;
	int bonus = 0;

	int result = cardEffect(tribute, 0, 0, 0, state, 0, &bonus);

	MYASSERT(result == 0);
	MYASSERT(state->numActions == 0);
	MYASSERT(state->coins == 0);
	MYASSERT(state->handCount[0] == 2);

	return 0;
}
