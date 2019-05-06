/*
 * cardtest3.c
 *
 
 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest3: cardtest3.c dominion.o rngs.o
 *      gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>s   

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

	// Verify if embargo actually adds two coins when called
	int initialCoins = G.coins;
	printf("At beginning of game player %d has %d coins\n\n", currentPlayer, G.coins);
	printf("cardEffect is called with a value chosen to switch to the embargo case:\n\n");
	cardEffect(embargo, 0, 0, 0, &G, handPos, 0);
	printf("Player %d now has %d coins!\n\n",currentPlayer, G.coins);
	if(assertTest((initialCoins+2),(G.coins)))
		printf("Embargo added the correct number of coins to the player!");
	else
		printf("Embargo DOES NOT add the correct number of coins for the player!\n");
	
    printf("\n------------------------------------------------------------------------------\n");
	return 0;
}