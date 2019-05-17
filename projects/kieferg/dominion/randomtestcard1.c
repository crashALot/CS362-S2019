/*
 * randomtestcard1.c
 *
 
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