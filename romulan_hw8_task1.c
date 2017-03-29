/*
 * =====================================================================================
 *
 *       Filename:  romulan_hw8_task1.c
 *       	Usage:  ./romulan_hw8_task1.c
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/23/2017 04:15:25 PM
 *       Compiler:  gcc -Wall -Werror
 *         Author:  Chris Werner (), christopherwerner@mail.weber.edu
 * =====================================================================================
 */
#include <stdio.h>		/* For Standard I/O */
#include <stdlib.h>		/* For Standard Library*/
#include <string.h>		/* For String library */

/* Function Prototypes */
void Usage(char** info);
char StringIn(char* str1, char* str2);

/* Main Program */
int main(int argc, char *argv[])
{
	// if input equals 1 or 4 or more parameters, call usage
	if (argc == 1 || argc >= 4)
	{
		printf("Missing required parameters\n");
		Usage(argv);
	}
	// if first input is --help, call Usage()
	else if (strcmp(argv[1],"--help") == 0)
	{
		printf("Help information\n");
		Usage(argv);
	}
	// if input equals 2 paramters (but NOT --help as 2nd) then call usage
	else if (argc == 2)
	{
		printf("Missing required paramters\n");
		Usage(argv);
	}
	StringIn(argv[1], argv[2]);
	

	return 0;
}


/* Function Defenitions */
void Usage(char** info)
{
	printf("Usage %s <str1> <str2>\n", *info);
	printf("Program checks if str2 is part of str1\n");
	exit(1);
	return;
}
char StringIn(char* str1, char* str2)
{
	int str1leng = strlen(str1);
	char s1;
	for (int i = 0; i < str1leng; i++)
	{
		if (*(str2) == *(str1++))
		{
			s1 = *(str1);
		}
	}
	printf("The first letter is %c\n", s1);

	return '0';
}
