/*
 * cardtest2.c
 *
 
 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest2: cardtest2.c dominion.o rngs.o
 *      gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int assertTest(int left, int right) {
	if (left==right)
		return 1;
	else
		return 0;
}

int main() {
    int seed = 1000;
    int numPlayer = 2;
	int r;
	int handPos=0;
	int currentPlayer = 0;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , cutpurse, smithy, village, baron, great_hall};
    struct gameState G;
	
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    printf("------------------------------------------------------------------------------\n");
	printf("\nInitializing a new game of dominion\n\n");
	r=initializeGame(numPlayer, k, seed, &G); // initialize a new game
	G.deckCount[currentPlayer]=30;
	// call the Smithy function and verify that current player deck is reduced by three cards every call
	int initialDeckCount=G.deckCount[currentPlayer];
	int deckCounter=G.deckCount[currentPlayer];
	printf("Initial deck count for player %d is: %d\n", currentPlayer, initialDeckCount);
	while (deckCounter>0)
	{
		printf("callSmithy function is called:\n");
		callSmithy(currentPlayer, &G, handPos);
		printf(" --> Your hand now has %d cards\n", G.handCount[currentPlayer]);
		printf(" --> Your deck now has %d cards\n\n", G.deckCount[currentPlayer]);
		if(assertTest((deckCounter-3),(G.deckCount[currentPlayer])))
			printf("Smithy removes the correct number of cards from the player's deck!");
		else
			printf("Smithy DOES NOT remove the correct number of cards from the player's deck!\n");
		deckCounter=deckCounter-3;
	}
	
	printf("\n------------------------------------------------------------------------------\n");
	return 0;
}