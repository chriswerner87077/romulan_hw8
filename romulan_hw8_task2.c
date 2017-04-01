/*
 * =====================================================================================
 *
 *       Filename:  romulan_hw8_task2.c
 *       	Usage:  ./romulan_hw8_task2.c
 *    Description:  Task2
 *
 *        Version:  1.0
 *        Created:  03/23/2017 04:15:31 PM
 *       Compiler:  gcc -Wall -Werror
 *         Author:  Sterling Woodruff, Chris Werner
 * =====================================================================================
 */
#include <stdio.h>		/* For Standard I/O */
#include <stdlib.h>		/* For standard Library */
#include <string.h>		/* For String Library */
#include <ctype.h>		/* For Character Library */

#define MAXCHARS 100
/* Function Prototypes */
void Usage(char** info);
char GetOptions(char *argv);
void PrintOption(char value);

/* Main Program */
int main(int argc, char *argv[])
{
	char val;
	// if does not equal 1 parameter, call usage
	if (argc != 2)
	{
		printf("Missing or wrong number of parameters\n");
		Usage(argv);
	}
	// if first input is --help, call Usage()
	else if (strcmp(argv[1],"--help") == 0)
	{
		printf("Help information\n");
		Usage(argv);
	}
	// Call GetOptions function and return it to val
	val = GetOptions(argv[1]);
	// Call PrintOption function
	PrintOption(val);

	return 0;
}


/* Function Defenitions */
void Usage(char** info)
{
	// Print usage on teh screen
	printf("Usage %s [-p | -u | -l]\n", *info);
	exit(1);

	return;
}

//Get input from user and return single letter p,u,l
char GetOptions(char* argv)
{
	// Declare variables
	char* value;
	// If the user input is one of the options, then parse input for option
	if(strcmp(argv, "-p") == 0 || strcmp(argv, "-u") == 0 || strcmp(argv, "-l") == 0)
	{
		value = strtok(argv,"-");
	}
	// Display and select default option, -p, if user input incorrect
	else
	{
		printf("%s is an invalid flag; using default flag (-p).\n", argv);
		value = "p";
	}
	printf("Selecting option %c.\n", *value);
	return *value;
}

void PrintOption(char value)
{
	// Declare variables
	char str1[MAXCHARS];
	char str2[MAXCHARS];
	int i = 0;
	float sentinel;
	// prompt user for input
	printf("Type input. Output will be based on option.\n");
	printf("Enter Ctrl-D to stop user input: ");
	// while loop to get and process input, only exits when Ctrl-D entered
	while (scanf("%f", &sentinel) != EOF)
	{
		i = 0;
		// while loop to capture each character and assign modified str1 to str2
		while ((str1[++i] = getchar()) != '\n')
		{
			if (value == 'u')
			{
				str2[i] = toupper(str1[i]);
			}
			else if (value == 'l') 
			{
				str2[i] = tolower(str1[i]);
			}
			else
			{
				str2[i] = str1[i];
			}
			// Print the modified character on the screen
			printf("%c", str2[i]);
		}
		// Provide new line after modified string is completely printed
		printf("\n");
	}

	return;
}

