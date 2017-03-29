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
void GetOptions(char *argv);
//void PrintOption(char *select);

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

	return 0;
}


/* Function Defenitions */
void Usage(char** info)
{
	printf("Usage %s [-p | -u | -l]\n", *info);
	exit(1);
	return;
}
void GetOptions(char *argv)
{
	char str1[MAXCHARS];
	char str2[MAXCHARS];
	int i = 0;
	float marker;
	// print the selected option and default if incorrect option is used
	if(strcmp(argv, "-p") == 0 || strcmp(argv, "-u") == 0 || strcmp(argv, "-l") == 0)
	{
		printf("Selecting option %s.\n", argv);
	}
	else
	{
		printf("%s is an invalid flag; using default flag (-p).\n", argv);
	}
	// prompt user for input
	printf("Type input. Output will be based on option.\n");
	printf("Enter Ctrl-D to stop user input: ");
	// while loop to get adn process input, only exits when Ctrl-D entered
	while (scanf("%f", &marker) != EOF)
	{
		// while loop to capture each character
		while ((str1[i++] = getchar()) != '\n')
			;
		i = 0;
		while (str1[i])
		{
			if (strcmp(argv,"-u") == 0)
			{
				str2[i] = toupper(str1[i]);
			}
			else if (strcmp(argv, "-l") == 0) 
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

/* void PrintOption(char *select)
{

	return;
}*/

