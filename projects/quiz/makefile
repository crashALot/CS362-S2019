CFLAGS= -Wall -fpic -coverage -lm -std=c99

testme: testme.o testme.c
	gcc -o testme testme.c -g $(CFLAGS)

testresults: testresults.out

testresults.out: testme.c
	
	echo "Result for running testme tests:" > testresults.out
	echo "testme.c:" >> testresults.out
	gcc -o testme testme.c $(CFLAGS)
	-./testme >> testresults.out
	gcov -b -c testme.c >> testresults.out

all: testme testresults

clean:
	rm -f *.o testresults.out testme.exe testme *.gcov *.gcda *.gcno *.so *.out
