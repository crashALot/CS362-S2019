#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
	int randVal=((rand()*INT_MAX)/INT_MAX)*10; // Creates random value between 0 and 9
	char charArr[9]={'[', '(', '{', ' ', 'a', 'x', '}', ')', ']'}; // Characters included in testme()
	char randChar=charArr[randVal];
    return randChar;
}

char *inputString()
{
    // TODO: rewrite this function
	// 97 123
	int randVal=((rand()*INT_MAX)/INT_MAX)*26; // Randomly selects value between 0 and 25
	char charArr[6]; // Character array that stores 5 characters and a delimiter
	// Fills character array with random string of characters
	for (int i=0; i<5; i++)
	{
		charArr[i]=122-randVal; // ASCII Math to convert int to char
	}
	charArr[5]='\0';
    return charArr;
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
