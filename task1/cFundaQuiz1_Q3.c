/* Program that creates a random number and stores it in files called file_1.txt upto file_9.txt */
 
#include <stdio.h>

int main(int arg, char* argv[])
{
	char c;

	c = getc(stdin);

	printf("%d\n", c);

	c = getc(stdin);

	return 0;
}