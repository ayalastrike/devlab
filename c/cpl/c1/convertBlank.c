#include	<stdio.h>
#include	<stdlib.h>

int
main(int argc, char **argv)
{

	int c;

	int lastC = EOF;

	while ( (c=getchar()) != EOF ) {
		if ( !(c == ' ' && lastC == ' ') ) {
			putchar(c);
		}

		lastC = c;
	}

	exit(0);
}
