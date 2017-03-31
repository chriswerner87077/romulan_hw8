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
#include <stdlib.h>
#include <string.h>		/* For String Library */
#include <ctype.h>		/* For Character Library */

#define MAXCHARS 100
/* Function Prototypes */
void Usage(char** info);
char GetOptions(char *argv);
void PrintOption(char *select);

/* Main Program */
int main(int argc, char *argv[])
{
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

	GetOptions(argv[1]);
	printf("%s\n", argv[1]);
	PrintOption(argv[1]);

	return 0;
}


/* Function Defenitions */
void Usage(char** info)
{
	printf("Usage %s [-p | -u | -l]\n", *info);
	exit(1);
	return;
}

//Get input from user and return single letter p,u,l
char GetOptions(char *argv)
{
	char value;
	if(strcmp(argv, "-p") == 0 || strcmp(argv, "-u") == 0 || strcmp(argv, "-l") == 0)
	{
		if(strchr(argv, 'p'))
		{
			value = 'p';
		}

		else if( strchr(argv, 'u'))
		{
			value = 'u';
		}

		else if( strchr(argv, 'l'))
		{
			value = 'l';
		}
		printf("Selecting option %c.\n", value);
	}
	else
	{
		printf("%s is an invalid flag; using default flag (-p).\n", argv);
	}
	return value;
}

//Print output based on return of GetOptions
void PrintOption(char *select)
{
	static char str1[MAXCHARS];
	static char str2[MAXCHARS];
	int i = 0;
	static float marker;
	// prompt user for input
	printf("Type input. Output will be based on option.\n");
	printf("Enter Ctrl-D to stop user input: ");
	// while loop to get and process input, only exits when Ctrl-D entered
	while (scanf("%f", &marker) != EOF)
	{
		// while loop to capture each character
		while ((str1[i++] = getchar()) != '\n')
			;
		i = 0;
		while (str1[i])
		{
			if (strcmp(select,"-u") == 0)
			{
				str2[i] = toupper(str1[i]);
			}
			else if (strcmp(select, "-l") == 0) 
			{
				str2[i] = tolower(str1[i]);
			}
			else
			{
				str2[i] = str1[i];
			}
			printf("%c", str2[i]);
			i++;
		}
	}

	return;
}

