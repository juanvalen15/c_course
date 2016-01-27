#include <stdio.h>

int main(int arg, char* argv[])
{
	char myname[80] = "your name";
	char *my_name_again;

	printf("%s\n", myname);

	my_name_again = myname;

	printf("%s\n", my_name_again);

	return 0;
}