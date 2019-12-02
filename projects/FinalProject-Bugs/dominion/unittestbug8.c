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

	struct gameState* state = newGame();
	state->numPlayers = 2;
	state->whoseTurn = 0;
	state->numActions = 0;
	state->coins = 0;
	state->numBuys = 0;
	state->handCount[0] = 1;
	state->hand[0][0] = minion;
	state->playedCardCount = 0;
	int bonus = 0;

	int result = cardEffect(minion, 1, 0, 0, state, 0, &bonus);

	MYASSERT(result == 0);
	MYASSERT(bonus == 2);

	return 0;
}
