CFLAGS= -Wall -fpic -coverage -lm -std=c99

randomtestresults: randomtestresults.out

randomtestresults.out: randomtestadventurer.c randomtestcard1.c randomtestcard2.c dominion.c rngs.c
	
	echo "Result for running random dominion tests:" >> randomtestresults.out
	echo " " >> randomtestresults.out
	
	echo "randomtestcard1.c:" >> randomtestresults.out
	gcc -o randomtestcard1 dominion.c rngs.c randomtestcard1.c $(CFLAGS)
	./randomtestcard1 >> randomtestresults.out
	gcov -b -c -f dominion.c >> randomtestresults.out
	
	echo "randomtestcard2.c:" >> randomtestresults.out
	gcc -o randomtestcard2 dominion.c rngs.c randomtestcard2.c $(CFLAGS)
	./randomtestcard2 >> randomtestresults.out
	gcov -b -c -f dominion.c >> randomtestresults.out
	
	echo "randomtestadventurer.c:" >> randomtestresults.out
	gcc -o randomtestadventurer dominion.c rngs.c randomtestadventurer.c $(CFLAGS)
	./randomtestadventurer >> randomtestresults.out
	gcov -b -c -f dominion.c >> randomtestresults.out

randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
	gcc -o randomtestadventurer -g randomtestadventurer.c dominion.o rngs.o $(CFLAGS)

randomtestcard1: randomtestcard1.c dominion.o rngs.o
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o $(CFLAGS)

randomtestcard2: randomtestcard2.c dominion.o rngs.o
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o $(CFLAGS)

all: randomtestresults

clean:
	rm -f *.o randomtestresults.out randomtestcard2.exe randomtestcard2 randomtestcard1.exe randomtestcard1 randomtestadventurer.exe randomtestadventurer *.gcov *.gcda *.gcno *.so *.out playdom player