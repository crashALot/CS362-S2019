/*
 * unittest1.c
 * Call Smithy card and check for bugs
 
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

int assertTest(int left, int right) {
	if (left==right)
		return 1;
	else
		return 0;
}

int main() {
    int seed = 1000;
    int numPlayer = 2;
	int r, initialHandCount;
	int currentPlayer = 0;
	int handPos = 0;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
	
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    printf("------------------------------------------------------------------------------\n");
	printf("\nInitializing a new game of dominion\n");
	r=initializeGame(numPlayer, k, seed, &G); // initialize a new game
	G.deckCount[currentPlayer]=30;
	initialHandCount=G.handCount[currentPlayer];
	printf("You currently have %d cards in hand\n", G.handCount[currentPlayer]);
	printf("Your deck currently has %d cards\n\n", G.deckCount[currentPlayer]);
	
	//printf("Your discarded card pile is %d cards\n\n", G.discardCount[currentPlayer]);
	printf("You are calling Smithy 1 time and adding a total of 3 cards to your hand\n");
	printf(" After using smithy you must discard it\n");
	printf("  ---> (3 cards gained) - (1 card discarded) = 2 cards gained total\n");
	
	smithyCard(currentPlayer, &G, handPos);
	printf("\nSmithy has been called\n");
	printf(" --> Your hand now has %d cards\n", G.handCount[currentPlayer]);
	printf(" --> Your deck now has %d cards\n\n", G.deckCount[currentPlayer]);
	//printf("Your discarded card pile is now %d cards\n", G.discardCount[currentPlayer]);
	
	printf("Assert if smithy added 2 cards (in total) to player hand\n\n");
	
	// Assert if initial hand count plus 2 additional cards is equivalent after calling smithy
	if(assertTest((initialHandCount+2),(G.handCount[currentPlayer]+3-1)))
		printf("Smithy adds the correct number of cards to the player's hand!");
	else
		printf("Smithy DOES NOT add the correct number of cards to the player's hand!\n");
	
	printf("------------------------------------------------------------------------------\n");
	return 0;
}