/*
 * cardtest4.c
 *
 
 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest4: cardtest4.c dominion.o rngs.o
 *      gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
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
	int handPos =0;
	int currentPlayer = 0;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , cutpurse, smithy, village, baron, great_hall};
    struct gameState G;
	
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    printf("------------------------------------------------------------------------------\n");
	printf("\nInitializing a new game of dominion\n\n");
	r=initializeGame(numPlayer, k, seed, &G); // initialize a new game
	int initialActions=G.numActions;
	// Determine if calling village will add 2 actions to player's state
	printf("Player %d actions are currently %d\n\n", currentPlayer, initialActions);
	printf("Call cardEffect function with village case argument:\n\n");
	cardEffect(village, 0, 0, 0, &G, handPos, 0);
	printf("Player %d number of actions has increased to: %d\n\n", currentPlayer, G.numActions);

	if(assertTest((initialActions+2),(G.numActions)))
		printf("Village added the correct number of actions to the player!");
	else
		printf("Village DOES NOT add the correct number of actions to the player!\n\n");

    printf("\n------------------------------------------------------------------------------\n");
	return 0;
}