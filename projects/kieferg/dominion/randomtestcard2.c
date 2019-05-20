/*
 * randomtestcard2.c
 * This program calls the refactored Minion function in dominion.c.
 * The program assembles a random number of players and assigns a random 
 * deck, hand, and played pile for each. Upon calling the Minion function 
 * the program evaluates if each player's hand is adjusted to the appropriate
 * number of cards once completed.
 
 */

/*
 * Include the following lines in your makefile:
 *
 * randomtestcard2: randomtestcard2.c dominion.o rngs.o
 *      gcc -o randomtestcard2 -g  randomtestcard2.c dominion.o rngs.o $(CFLAGS)
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
	int seed = 1000;
	int currentPlayer = 0;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , cutpurse, smithy, village, baron, great_hall};
	struct gameState G;
	
	int handPos=0;
	int choice1=0, choice2=1; // Ensure Minion call always uses choice 2
	int startHandCount[MAX_PLAYERS], startDeckCount[MAX_PLAYERS], startPlayedCount=0;
	int passCount=0, failCount=0; // Track number of passed or failed random test cases
	
	for (int k=0; k<1000; k++)
	{
	
		// Randomly assign number of players between 1 and MAX_PLAYERS
		G.numPlayers = rand()%MAX_PLAYERS+1;
		
		// Randomly assign hand size to each player between 0 and 100
		for (int i=0; i<G.numPlayers; i++)
		{
			G.handCount[i]=rand()%100;
			startHandCount[i]=G.handCount[i];
		}
		
		// Randomly assign deck size to each player between 5 and 100
		for (int i=0; i<G.numPlayers; i++)
		{
			G.deckCount[i]=rand()%100+5;
			startDeckCount[i]=G.deckCount[i];
		}
		
		// Randomly assign played pile for game between 0 and MAX_DECK
		G.playedCardCount=rand()%MAX_DECK;
		startPlayedCount=G.playedCardCount;
		
		// Iterate through each player and assign cards to their hand, deck, and discard pile
		// Add cards to player's hands
		for (int i=0; i<G.numPlayers; i++)
		{
			for (int j=0; j<G.handCount[i]; j++)
			{
				G.hand[i][j]=rand()%27;
			}
		}
		
		// Add cards to player's decks
		for (int i=0; i<G.numPlayers; i++)
		{
			for (int j=0; j<G.deckCount[i]; j++)
			{
				G.deck[i][j]=rand()%27;
			}
		}
		
		//Add cards to played pile
		for (int i=0; i<G.playedCardCount; i++)
		{
			G.playedCards[i]=rand()%27;
		}
		
		printf("------------------------------------------------------------------------------\n");
		
		printf("Card decks, player hands, and played piles initialized for Minion function call\n\n");
		
		for (int i=0; i<G.numPlayers; i++)
			printf("Player %d is starting with %d cards in hand\n",i,G.handCount[i]);
		
		callMinion(&G, handPos, currentPlayer, choice1, choice2);
		
		// Assert that current player discards hand and draws 4 new cards
		if (assertTest(G.handCount[currentPlayer],4))
		{
			printf(" ++ Current player started with %d cards and now has %d cards in their hand!\n", startHandCount[currentPlayer],G.handCount[currentPlayer]);
			passCount++;
		}
		else
		{
			printf(" -- Current player does not have the proper number of cards in their hand!\n");
			failCount++;
		}
		
		// Assert that players who originally had 5+ cards in-hand now only have 4
		for (int i=1; i<G.numPlayers; i++)
		{
			if (startHandCount[i]>=5)
			{
				if (assertTest(G.handCount[i],4))
				{
					printf(" ++ Player %d originally had %d cards in hand, they now have 4!\n", i, startHandCount[i]);
					passCount++;
				}
				else
				{
					printf(" -- Player %d originally had %d cards in hand, they now have %d!\n", i, startHandCount[i], G.handCount[i]);
					failCount++;
				}
			}
		}
		
		// Assert that players who originally had 5+ cards discarded all cards appropriately
		// Calculate total number of discarded cards
		int runTotal=startHandCount[currentPlayer]; // Current player automatically discards hand
		for (int i=0; i<G.numPlayers; i++)
		{
			if (startHandCount[i]>=5)
			{
				runTotal=(runTotal+startHandCount[i]);
			}
		}
		
		if (assertTest(startPlayedCount+runTotal,G.playedCardCount))
		{
			printf(" ++ There were originally %d cards in the played pile, now there are %d\n!", startPlayedCount, G.playedCardCount);
			passCount++;
		}
		else
		{
			printf(" -- There were originally %d cards in the played pile, now there are %d\n!", startPlayedCount, G.playedCardCount);
			failCount++;
		}
	}	
	
	printf("Total failed tests: %d\n", failCount);
	printf("Total passed tests: %d\n", passCount);
	printf("------------------------------------------------------------------------------\n");
	return 0;
	return 0;
}