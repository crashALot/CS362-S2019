/*
 * randomtestadventurer.c
 *
 
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
	
	
	
	return 0;
}