#include	<stdio.h>
#include	<stdlib.h>

#define MAXLINE 	1000

int getline2(char[], int);
int strindex(char[], char[]);

char pattern [] = "ould";

int
main(int argc, char **argv)
{
	char line[MAXLINE];

	int found = 0;

	while ( getline2(line, MAXLINE) > 0 ) {
		if ( strindex(line, pattern) >=0 ){
			printf("%s\n", line);
			found++;
		}
	}

	printf("found:%d", found);
	
	exit(0);
}