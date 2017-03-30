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
char* StringIn(char* str1, char* str2);

/* Main Program */
int main(int argc, char *argv[])
{
	// declare variable 
	char* start;
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
	// Call StringIn function and assign returned value to variable
	start = StringIn(argv[1], argv[2]);
	// use returned value to determine if string was found or not based
	// whether or not the returned value exists (i.e. is the NULL char)
	if (start)
	{
		printf("<%s> found in <%s>\n", argv[2], argv[1]);
	}
	else
	{
		printf("<%s> NOT found in <%s>\n", argv[2], argv[1]);
	}
	// print the returned string
	printf("Returned string <%s>\n", start);

	return 0;
}


/* Function Defenitions */
void Usage(char** info)
{
	// Print the usage function information and exit
	printf("Usage %s <str1> <str2>\n", *info);
	printf("Program checks if str2 is part of str1\n");
	exit(1);

	return;
}
char* StringIn(char* str1, char* str2)
{
	// declare and initialize variables
	int str2leng = strlen(str2);
	char* s1 = '\0';
	// enter loop
	do
	{
		// compare length of str2 to str1 (where str1 is at in the loop)
		if (strncmp(str2,str1, str2leng) == 0) 
		{
			// assign str1 current address to s1
			s1 = str1;
		}
	}while (*(str1++));

	return s1;
}
