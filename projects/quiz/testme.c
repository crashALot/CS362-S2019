#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
    int maxNum=9, minNum=0;
	int randVal=rand()%(maxNum+1-minNum)+minNum; // Creates random value between 0 and 9
    //printf("randVal is %d\n", randVal);
	char charArr[9]={'[', '(', '{', ' ', 'a', 'x', '}', ')', ']'}; // Characters included in testme() that we'll be testing against
	char randChar=charArr[randVal];
    return randChar;
}

char *inputString()
{
    // TODO: rewrite this function
    int maxNum=4, minNum=0;
	char charArr[6]; // Character array that stores 5 characters and a delimiter
    char randChar[4]={'r','e','s','t'};
	// Fills character array with random string of characters
	for (int i=0; i<5; i++)
	{
		charArr[i]=randChar[rand()%(maxNum+1-minNum)+minNum]; // ASCII Math to convert int to char, in this case randomly selects lower case letters
	}
	charArr[5]='\0'; //  Terminate C-string
    /*
    for (int i=0; i<6; i++)
    {
        printf("%c ", charArr[i]);
    }
    printf("\n");
    */
    char *stringPtr=charArr;
    
    return stringPtr;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}