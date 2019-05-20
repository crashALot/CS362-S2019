/*
 * randomtestcard1.c
 * This program calls the refactored Smithy function in dominion.c.
 * The program initializes the game state to a random collection and assortment
 * of cards in the game deck, player hand, and played pile. After calling the
 * Smithy function the program than asserts that the number of cards left in the player
 * hand is correct, the cards removed from the deck is correct, and the cards added to
 * the played pile is also correct.
 
 */

/*
 * Include the following lines in your makefile:
 *
 * randomtestcard1: randomtestcard1.c dominion.o rngs.o
 *      gcc -o randomtestcard1 -g  randomtestcard1.c dominion.o rngs.o $(CFLAGS)
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
	
	int handPos=0;
	int passCount=0, failCount=0; // Track number of passed or failed random test cases
	
	printf("------------------------------------------------------------------------------\n");
	
	for (int j=0; j<2000; j++)
	{
		memset(&G, 23, sizeof(struct gameState)); // Clear game state

		// Randomly select number of cards in starting deck between 0 and 1000 and store in game state
		G.deckCount[currentPlayer]=rand()%1000;
		
		// Fill player deck with random assortment of cards
		for (int i=0; i<G.deckCount[currentPlayer]; i++)
		{
			G.deck[currentPlayer][i]=rand()%27;
			//printf("%d\n",G.deck[currentPlayer][i]);
		}
		
		// Randomly select number of cards in player hand between 0 and 1000 and store in game state
		G.handCount[currentPlayer]= rand()%1000;

		// Fill player hand with random assortment of cards
		for (int i=0; i<G.handCount[currentPlayer]; i++)
		{
			G.hand[currentPlayer][i]=rand()%27;
			//printf("%d\n",G.hand[currentPlayer][i]);
		}
		
		// Randomly select number of cards in played pile between 0 and 1000 and save to game state
		G.playedCardCount=rand()%1000;
		
		// Fill played pile with random assortment of cards
		for (int i=0; i<G.playedCardCount; i++)
		{
			G.playedCards[i]=rand()%27;
			//printf("%d\n",G.discard[currentPlayer][i]);
		}
		
		printf("Card deck, player hand, and played pile initialized for Smithy function call\n\n");
		
		printf("Before calling Smithy current player %d has:\n", currentPlayer);
		printf("  %d cards in their hand\n", G.handCount[currentPlayer]);
		int beforeSmithyHand = G.handCount[currentPlayer];
		printf("   %d cards in their deck\n", G.deckCount[currentPlayer]);
		int beforeSmithyDeck = G.deckCount[currentPlayer];
		printf("    %d cards in the played pile\n", G.playedCardCount);
		int beforeSmithyPlayed = G.playedCardCount;

		callSmithy(currentPlayer, &G, handPos);

		printf("After calling Smithy current player %d now has:\n", currentPlayer);
		printf("  %d cards in their hand\n", G.handCount[currentPlayer]);
		printf("   %d cards in their deck\n", G.deckCount[currentPlayer]);
		printf("    %d cards in the played pile\n\n", G.playedCardCount);
		
		if (assertTest(beforeSmithyHand+2,G.handCount[currentPlayer]))
		{
			printf(" ++ 3 cards were added to the player's hand a nd one was discarded!\n");
			passCount++;
		}
		else
		{
			failCount++;
			printf(" -- The incorrect number of cards were added to the player's hand!\n");
		}
		
		if (assertTest(beforeSmithyDeck-3,G.deckCount[currentPlayer]))
		{
			printf(" ++ 3 cards were drawn from the player's deck!\n");
			passCount++;
		}
		else
		{
			failCount++;
			printf(" -- The incorrect number of cards were taken from the player's deck!\n");
		}
		
		if (assertTest(beforeSmithyPlayed+1,G.playedCardCount))
		{
			printf(" ++ 1 card was added to the played pile!\n\n");
			passCount++;
		}
		else
		{
			failCount++;
			printf(" -- The incorrect number of cards were added to the played pile! \n\n");
		}
	}
	
	printf("Total failed tests: %d\n", failCount);
	printf("Total passed tests: %d\n", passCount);
	printf("------------------------------------------------------------------------------\n");
	return 0;
}