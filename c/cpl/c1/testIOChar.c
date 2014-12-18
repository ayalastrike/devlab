#include	<stdio.h>
#include	<stdlib.h>

int
main(int argc, char **argv)
{
	int c;

	printf("EOF=%d\n", EOF);

	while ( (c = getchar()) != EOF ) {
		putchar(c);
	}

	exit(0);
}
