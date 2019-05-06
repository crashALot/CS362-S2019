/*
 * unittest3.c
 *
 
 */

/*
 * Include the following lines in your makefile:
 *
 * unittest3: unittest3.c dominion.o rngs.o
 *      gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
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
               , cutpurse, smithy, village, baron, great_hall};
    struct gameState G;
	
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    printf("------------------------------------------------------------------------------\n");
	printf("\nInitializing a new game of dominion\n");
	r=initializeGame(numPlayer, k, seed, &G); // initialize a new game
	
	// We'll automatically iterate through an assortment of estate supply test cases and see if the game
	// continues from 8 estates in play to 0 (when a player would win)
	
	printf("\nThere are %d estates in supply at the start of this game\n", supplyCount(estate, &G));
	int countEstates=G.supplyCount[estate];
	
	while (G.supplyCount[estate]>0)
	{
		printf(" -> There are currently %d estates and the game goes on!\n", supplyCount(estate, &G));
		// call Baron and be sure to choose an estate, this will remove the total estates from the game supply
		printf("   - callBaron function is called\n");
		callBaron(&G, currentPlayer, 1);
		assert(!isGameOver(&G));
		printf(" -> There are currently %d estates and the game goes on!\n", supplyCount(estate, &G));
		// call Baron and be sure to choose an estate, this will remove the total estates from the game supply
		printf("   - callBaron function is called\n");
		callBaron(&G, currentPlayer+1, 1);
		assert(!isGameOver(&G));
	}
	
	printf("\nWhen calling baron through a variety of estate supply values no issues are noted\n");
	printf("\n");
	
	return 0;
}