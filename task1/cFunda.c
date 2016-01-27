/* Program that creates a random number and stores it in files called file_1.txt upto file_9.txt */
 
#include <stdio.h>

int random_number_generator(int seed);

int main(int arg, char* argv[])
{
	int random_number;

	random_number = random_number_generator(3);

	printf("%d\n", random_number);
	getc(stdin);

	return 0;
}

int random_number_generator(int seed)
{
	int number;
	number = seed * 1103515245 + 12345;

	return (unsigned int)(number / 65536) % 32768;
}