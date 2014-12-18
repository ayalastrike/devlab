#include 	<stdio.h>
#include	<stdlib.h>

#define LOWER	0
#define UPPER	300
#define STEP	20

int
main(int argc, char **argv)
{

	float fahr, celsius;
	
	fahr = LOWER;

	printf("fahr\tcelsius\n");

	while (fahr <= UPPER) {
		celsius = 5*(fahr-32)/9;
		printf("%3.0f\t%6.1f\n", fahr, celsius);
		fahr += STEP;
	}

	exit(0);
}
