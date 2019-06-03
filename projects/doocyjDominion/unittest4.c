/*
 * unittest4.c
 * Call Minion card and check for bugs
 
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
	// Minion is called through card effect function as team mate did not refactor code
	// Choice 1 must be selected for appropriate action to be taken
	cardEffect(minion, 1, 0, 0, &G, handPos, 0);
	//Old code
	// callMinion(&G, handPos, currentPlayer, choice1, choice2);
	printf("Player %d now has %d coins\n\n", currentPlayer, G.coins);
	if(assertTest((initialCoin+2),G.coins))
		printf("Minion added the correct number of coins to the player!");
	else
		printf("Minion DOES NOT add the correct number of coins for the player!\n");
	
	printf("cardEffect Minion when selecting choice 1 returns an increase of 2 coins\n");
	printf("\n------------------------------------------------------------------------------\n");

	return 0;
}

