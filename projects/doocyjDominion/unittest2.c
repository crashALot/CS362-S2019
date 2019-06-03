/*
 * unittest2.c
 * Call Cut Purse card and check for bugs
 
 */

/*
 * Include the following lines in your makefile:
 *
 * unittest2: unittest2.c dominion.o rngs.o
 *      gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
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
    int numPlayer = 4;
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
	printf("Copper is an enumerated variable with a value of: %d. Silver is %d and gold %d\n\n", copper, silver, gold);
	// Ensure each player has at least one copper in hand
	// For the sake of brevity we'll set the first card in each hand to copper
	// the last position to silver, and the rest to gold

	for (int i=0; i<numPlayer; i++)
	{
	G.hand[i][0]=copper;
	G.hand[i][1]=gold;
	G.hand[i][2]=gold;
	G.hand[i][3]=gold;
	G.hand[i][4]=silver;
	G.handCount[i]=5;
	printf("Card for player %d at position 0 is %d (aka copper)\n", i, G.hand[i][0]);
	}
	
	// Call cut purse through card effect function, since team mate did not refactor cutpurse code
	printf("\ncutpurse will be called:\n\n");
	cardEffect(cutpurse, 0, 0, 0, &G, handPos, 0);
	// Old code
	// callCutPurse(currentPlayer, &G, handPos);
	
	// Output card value in position 0 of each opposing player's hand
	for (int i=0; i<numPlayer; i++)
	{
		if (i!=currentPlayer)
		printf("Player %d now has card %d in position 0 of their hand\n", i, G.hand[i][0]);
	}
	
	printf("\n");
	
	// Assert each player has lost at least one copper
	for (int i=0; i<numPlayer; i++)
	{
		if (i!=currentPlayer)
		{
			for (int j=0; j<G.handCount[i]; j++)
			{
				assert(G.hand[i][0]!=copper);
			}
		printf(" -> Player %d has lost their copper piece!\n", i);
		}
	}
	
	printf("\n cutpurse has successfully removed copper from each opposing player \n\n");
	printf("\n------------------------------------------------------------------------------\n");
	return 0;
}