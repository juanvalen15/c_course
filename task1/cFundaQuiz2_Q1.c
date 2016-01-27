/* Program that creates a random number and stores it in files called file_1.txt upto file_9.txt */
 
#include <stdio.h>

int main(int arg, char* argv[])
{
	char myname[20] = "Abracadabra";
	char mychar, newchar;

	putc(myname[0], stdout);
	putc(myname[1], stdout);

	printf("\n %d, %d\n", myname[0], myname[1]);
	printf("size of character = %lu\n", sizeof(char));

	mychar 	= 'a';
	newchar	= mychar + 9;

	printf("newchar = %c, value = %d\n", newchar, newchar);

	printf("size of unsigned int = %lu, size of int = %lu\n", sizeof(unsigned int), sizeof(int));

	return 0;
}