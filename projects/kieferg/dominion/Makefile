CFLAGS= -Wall -fpic -coverage -lm -std=c99

unittestresults: unittestresults.out

unittestresults.out: randomtestadventurer.c randomtestcard1.c randomtestcard2.c dominion.c rngs.c
	
	echo "Result for running random dominion tests:" > unittestresults.out
	
	echo "randomtestcard1.c:" >> unittestresults.out
	gcc -o randomtestcard1 dominion.c rngs.c randomtestcard1.c $(CFLAGS)
	./randomtestcard1 >> unittestresults.out
	gcov -b -c dominion.c >> unittestresults.out
	
	echo "randomtestcard2.c:" >> unittestresults.out
	gcc -o randomtestcard2 dominion.c rngs.c randomtestcard2.c $(CFLAGS)
	./randomtestcard2 >> unittestresults.out
	gcov -b -c dominion.c >> unittestresults.out
	
	echo "randomtestadventurer.c:" >> unittestresults.out
	gcc -o randomtestadventurer dominion.c rngs.c randomtestadventurer.c $(CFLAGS)
	./randomtestadventurer >> unittestresults.out
	gcov -b -c dominion.c >> unittestresults.out

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)

randomtestcard1: randomtestcard1.c dominion.o rngs.o
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)

randomtestcard2: randomtestcard2.c dominion.o rngs.o
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o $(CFLAGS)

all: unittestresults

clean:
	rm -f *.o unittestresults.out randomtestcard2.exe randomtestcard2 randomtestcard1.exe randomtestcard1 randomtestadventurer.exe randomtestadventurer *.gcov *.gcda *.gcno *.so *.out