#include	<stdio.h>
#include	<stdlib.h>

#define LOWER	0
#define UPPER	300
#define STEP	20

float calcTemp(float);

int
main(int argc, char **argv)
{
	float fahr;
	fahr = 0;

	printf("fahr\tcelsius\n");

	while ( fahr <= UPPER ) {
		printf("%3.0f\t%6.1f\n", fahr, calcTemp(fahr));

		fahr += STEP;
	}

	exit(0);
}

float
calcTemp(float f)
{
	return 5*(f-32)/9;
}