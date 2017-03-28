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

/* Function Prototypes */
void Usage(char** info);
//void GetOptions(char );
//void PrintOption(char );

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

	return 0;
}


/* Function Defenitions */
void Usage(char** info)
{
	printf("Usage %s [-p | -u | -l]\n", *info);
	exit(1);
	return;
}
/*char StringIn(char* str1, char* str2)
{
	exit(1);
	return '0';
}*/
