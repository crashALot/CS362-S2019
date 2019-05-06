/*
 * unittest4.c
 *
 
 */

/*
 * Include the following lines in your makefile:
 *
 * unittest4: unittest4.c dominion.o rngs.o
 *      gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
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
	int choice1=1;
	int choice2=0;
	int handPos = 0;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , cutpurse, smithy, village, baron, great_hall};
    struct gameState G;
	
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    printf("------------------------------------------------------------------------------\n");
	printf("\nInitializing a new game of dominion\n");
	r=initializeGame(numPlayer, k, seed, &G); // initialize a new game
	// Save initial qunatity of coins
	int initialCoin = G.coins;
	printf("Current coins of player %d is: %d\n", currentPlayer, G.coins);
	// If a user enters choice 1 we want to test that the player gets a +2 higher coin count
	printf("\ncallMinions will be called:\n\n");
	callMinion(&G, handPos, currentPlayer, choice1, choice2);
	printf("Player %d now has %d coins\n\n", currentPlayer, G.coins);
	assert(initialCoin+2==G.coins);
	
	printf("Function callMinion when selecting choice 1 returns an increase of 2 coins\n");
	printf("\n------------------------------------------------------------------------------\n");

	return 0;
}

