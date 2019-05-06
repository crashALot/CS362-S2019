/*
 * cardtest1.c
 *
 
 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest1: cardtest1.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)
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
	int drawntreasure=100; // Should be 0!
	int currentPlayer = 0;
	int temphand[MAX_HAND];
	int z=0;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , cutpurse, smithy, village, baron, great_hall};
    struct gameState G;
	
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    printf("------------------------------------------------------------------------------\n");
	printf("\nInitializing a new game of dominion\n\n");
	r=initializeGame(numPlayer, k, seed, &G); // initialize a new game
	
	// Attempt to identify if adventurer draws any new cards if inappropriate drawTreasure argument is sent to function
	int initialHand=G.handCount[currentPlayer];
	printf("hand count for player %d is: %d\n", currentPlayer, initialHand);
	printf("callAdventurer function is called with inappropriate drawntreasure argument:\n");
	callAdventurer(cutpurse, drawntreasure, &G, currentPlayer, temphand, z);
	printf("hand count for player %d is now: %d\n", currentPlayer, G.handCount[currentPlayer]);
	assert(initialHand==G.handCount[currentPlayer]);
	printf("\nNo new cards were added to the players hand!\n");
	printf("\n------------------------------------------------------------------------------\n");
	return 0;
}