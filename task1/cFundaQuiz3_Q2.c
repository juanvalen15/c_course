/* Program that creates a random number and stores it in files called file_1.txt upto file_9.txt */
 
#include <stdio.h>

int main(int arg, char* argv[])
{
	int house = 1234;
	int *which_house = &house;
	*which_house = 5678;
	printf("house = %d\n", house);

	int **which_which_house = &which_house;
	//int another_house = 90;
	//*which_which_house = &another_house;
	printf("%d\n", *which_house);

	return 0;
}