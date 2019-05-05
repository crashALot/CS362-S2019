/*
 * unittest1.c
 *
 
 */

/*
 * Include the following lines in your makefile:
 *
 * unittest1: unittest1.c dominion.o rngs.o
 *      gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {
    int seed = 1000;
    int numPlayer = 2;
	int r;
	int currentPlayer = 0;
	int handPos = 0;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
	
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    printf("Initializing a new game of dominion\n");
	r = initializeGame(numPlayer, k, seed, &G); // initialize a new game
	printf("You currently have %d cards in hand\n", G.handCount[currentPlayer]);
	
	printf("You are calling Smithy 3 times and adding a total of 9 cards\n");
	for (int i=0; i<3; i++)
	{
		callSmithy(currentPlayer, &G, handPos);
		printf("Your hand now has %d cards\n", G.handCount[currentPlayer]);
	}
	return 0;
}