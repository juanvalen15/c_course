#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

extern int random_number_generator(int seed);
extern int create_list_of_numbers();
extern int add_number_to_list(int number);
extern void add_strings_to_list();
extern char *get_poetry_line(int mum);
extern char *get_first_word(char *line);

struct num_and_string
{
	int number;
	char *poetry;
	struct num_and_string *next;
};

struct num_and_string *ns_list;

char *number_map[10] = {"One", "Two", "Three", "Four", "Five",
					    "Six", "Seven", "Eight", "Nine", "Ten"};

int main(int arg, char* argv[])
{
	int i, len, random_number;
	char filename[20];
	FILE *fp;

	ns_list = NULL; // initialize list: list is empty when the program starts to run

	for (i=0; i < 10; i++)
	{
		random_number = random_number_generator(i);
		printf("seed = %d rand = %d\n", i, random_number);

		strcpy(filename, "file_");
		len = strlen(filename);
		filename[len] = '0' + i;
		filename[len+1] = '\0';
		strcat(filename, ".txt");
		printf("filename = %s\n", filename);

		fp = fopen(filename, "w");
		if ( fp == NULL )
		{
			printf("Error opening file: %s\n", filename);
			return 1;
		}
		fprintf(fp, "%d\n", random_number);
		fclose(fp);
	}

	create_list_of_numbers();
	add_strings_to_list();
	
	getc(stdin);

	return 0;
}

int random_number_generator(int seed)
{
	int number;
	
	number = seed * 1103515245 + 12345;
	return (unsigned int)(number / 65536) % 32768;
}

int create_list_of_numbers()
{
	int i, len, random_number;
	char filename[20];
	FILE *fp;
	struct num_and_string *temp_node;

	for ( i=0; i<10; i++)
	{
		strcpy(filename, "file_");
		len = strlen(filename);
		filename[len] = '0' + i;
		filename[len+1] = '\0';
		strcat(filename, ".txt");

		fp = fopen(filename, "r");
		if ( fp == NULL )
		{
			printf("Error opening file: %s\n", filename);
			return 1;
		}
		fscanf(fp, "%d", &random_number);
		printf("filename = %s number = %d\n", filename, random_number);
		add_number_to_list(random_number); 

		fclose(fp);
	}

	temp_node = ns_list;

	while( temp_node != NULL)
	{
		printf("list member: number: %d\n", temp_node->number);
		temp_node = temp_node->next;
	}

	return 0;
}

int add_number_to_list(int number)
{
	struct  num_and_string *new_node, *temp_node;
	
	new_node = (struct num_and_string *)malloc(sizeof(struct num_and_string)); // get size of struct and allocate those bytes of memory
	if(new_node == NULL)
	{
		printf("Error allocating memory: %d\n", number);
		return 1;
	}

	new_node->number = number;
	new_node->poetry = NULL;
	new_node->next = NULL;

	if(ns_list == NULL) /// the list if empty
	{
		ns_list = new_node;
		return 0;
	}
	else // list is not empty
	{
		temp_node = ns_list;

		while( temp_node->next != NULL)
		{
			temp_node = temp_node->next;
		}

		// here, temp_node is the last element in the list
		temp_node->next = new_node;
	}
	return 0;
}

void add_strings_to_list()
{
	struct num_and_string *temp_node;
	int i;

	temp_node = ns_list;
	i = 0;

	while( temp_node != NULL)
	{		
		temp_node->poetry = get_poetry_line(i);
		i++;
		if(temp_node->poetry != NULL)
			printf("i = %d, %s\n", i, temp_node->poetry);
		temp_node = temp_node->next;
	}
}

char *get_poetry_line(int num)
{
	FILE *fp;
	char line[80];
	char *word, *poetry_line;

	if (num > 9)
	{
		printf("Wrong arg num: %d\n", num);
		return NULL;
	}

	fp = fopen("ten_green_bottles.txt", "r");
	if(fp == NULL)
	{
		printf("Error: cannot open file: ten_green_bottles.txt\n");
		return NULL;
	}

	while( fgets(line, 70, fp) )
	{
		word = get_first_word(line);

		if (word != NULL)
		{
			if(strcmp(word, number_map[num]) == 0)
			{
				poetry_line = (char *)malloc(strlen(line) + 1);
				if (poetry_line == NULL)
				{
					printf("Error: cannot allocate memmory: %d\n", num);
					fclose(fp);
					return NULL;
				}
				strcpy(poetry_line, line);
				fclose(fp);
				return poetry_line;
			}
		}
	}
	fclose(fp);
	return NULL;
}


char *get_first_word(char *line)
{
	static char word[10];
	int i, j;

	i = 0;
	j = 0;

	while ( (line[i] != 0) && isspace(line[i]) )
		i++;

	if(line[i] == 0)
	{
		return NULL;
	}
	while( (line[i] != 0) && isalpha(line[i]) )
	{
		word[j] = line[i];
		i++;
		j++;
	}

	word[j] = 0;
	return word;
}





























