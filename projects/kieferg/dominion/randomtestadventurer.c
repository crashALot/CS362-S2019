/*
 * randomtestadventurer.c
 * This program calls the refactored Adventurer function in dominion.c and
 * randomly assigns deck size, hand size, and treasure card positions.
 * Assertions are made to prove whether or not the affected game state 
 * variables are appropriately changed after each iteration. Ultimately
 * the program checks if the player ends up with two treasure cards in hand
 * and no treasure cards in the resulting deck.
 
 */

/*
 * Include the following lines in your makefile:
 *
 * randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
 *      gcc -o randomtestadventurer -g  randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <time.h> 

int assertTest(int left, int right) {
	if (left==right)
		return 1;
	else
		return 0;
}

int main() {
	srand(time(0));
	int currentPlayer = 0;
	struct gameState G;
	
	int temphand[MAX_HAND];
	int cardDrawn;
	int z=0;
	int cardList[]={0,1,2,3,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25}; // Store card list in array, omitting any coin cards
	int passCount=0, failCount=0; // Track number of passed or failed random test cases
	
	printf("------------------------------------------------------------------------------\n");
	for (int j=0; j<1000; j++)
	{
		memset(&G, 23, sizeof(struct gameState)); // Clear game state

		// Randomly select number of cards in starting deck between 5 and 30 and store in game state
		G.deckCount[currentPlayer]=rand()%26+5;
		
		// Fill player deck with random assortment of cards, omitting any coin cards
		for (int i=0; i<G.deckCount[currentPlayer]; i++)
		{
			G.deck[currentPlayer][i]=cardList[rand()%24];
			//printf("%d\n",G.deck[currentPlayer][i]);
		}
		
		// Randomly pick two locations in deck and insert coin cards
		int randPosit;
		for (int i=0; i<2; i++)
		{
			randPosit=rand()%G.deckCount[currentPlayer];
			G.deck[currentPlayer][randPosit]=6; // 6 represents gold in the card list
		}
		
		// Randomly select number of cards in player hand between 1 and 5 and store in game state
		G.handCount[currentPlayer]= rand()%5+1;

		// Fill player hand with random assortment of cards, omitting any coin cards
		for (int i=0; i<G.handCount[currentPlayer]; i++)
		{
			G.hand[currentPlayer][i]=cardList[rand()%24];
			//printf("%d\n",G.hand[currentPlayer][i]);
		}
		
		// Initialize discard pile to 0
		G.discardCount[currentPlayer]=0;
		
		printf("Card deck and player hand initialized for Adventurer function call\n\n");
		
		printf("Before calling Adventurer current player %d has:\n", currentPlayer);
		printf("  %d cards in their hand\n", G.handCount[currentPlayer]);
		printf("   %d cards in their deck\n", G.deckCount[currentPlayer]);
		printf("    %d cards in their discard\n", G.discardCount[currentPlayer]);

		callAdventurer(cardDrawn, 0, &G, currentPlayer, temphand, z);

		printf("After calling Adventurer current player %d now has:\n", currentPlayer);
		printf("  %d cards in their hand\n", G.handCount[currentPlayer]);
		printf("   %d cards in their deck\n", G.deckCount[currentPlayer]);
		printf("    %d cards in their discard\n\n", G.discardCount[currentPlayer]);
		
		// assert that two treasures have been removed from deck and placed in player's hand
		int handTreasure=0, deckTreasure=0;
		for (int i=0; i<G.handCount[currentPlayer]; i++)
		{
			if(G.hand[currentPlayer][i]==6)
				handTreasure++;
		}
		
		for (int i=0; i<G.deckCount[currentPlayer]; i++)
		{
			if(G.deck[currentPlayer][i]==6)
				deckTreasure++;
		}
		
		if(assertTest(handTreasure,2) && assertTest(deckTreasure,0))
		{
			printf(" ++ Two treasures remain in player's hand!\n\n");
			passCount++;
		}
		if(assertTest(deckTreasure,2) && assertTest(handTreasure,0))
		{
			printf(" >> Two treasures were found still in the deck!\n\n");
			failCount++;
		}
		if(!assertTest(deckTreasure,2) && !assertTest(handTreasure,2))
		{
			printf(" -- Something went wrong!\n\n");
			failCount++;
		}
	}
	
	printf("Total failed tests: %d\n", failCount);
	printf("Total passed tests: %d\n", passCount);
	printf("------------------------------------------------------------------------------\n");
	return 0;
}