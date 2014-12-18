#include	<stdio.h>
#include	<stdlib.h>

int
main (int argv, char **argc)
{

	double wordCnt;

	for (wordCnt = 0; getchar() != EOF; wordCnt++) {
		;
	}

	printf("%.0f\n", wordCnt);

	exit(0);
}
