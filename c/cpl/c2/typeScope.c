#include	<limits.h>
#include	<stdio.h>
#include	<stdlib.h>

int
main(int argc, char **argv)
{
	// signed types
	printf("signed types\n");
	printf("signed char min = 	%20d\n",  SCHAR_MIN);
	printf("signed char max = 	%20d\n",  SCHAR_MAX);
	printf("signed short min =	%20d\n", SHRT_MIN);
	printf("signed short max = 	%20d\n", SHRT_MAX);
	printf("signed int min = 	%20d\n",   INT_MIN);
	printf("signed int max = 	%20d\n",   INT_MAX);
	printf("signed long min = 	%20ld\n",  LONG_MIN);
	printf("signed long max = 	%20ld\n",  LONG_MAX);

	// unsigned types
	printf("\nunsigned types\n");
	printf("unsigned char max =	%20u\n",  UCHAR_MAX);
	printf("unsigned short max = 	%20u\n", USHRT_MAX);
	printf("unsigned int max =	%20u\n",   UINT_MAX);
	printf("unsigned long max = 	%20lu\n",  ULONG_MAX);

	// calc signed types
	printf("\nsigned types\n");
	printf("signed char min =	%20d\n",  -(char)((unsigned char)~0 >> 1)-1);
	printf("signed char max =	%20d\n",  (char)((unsigned char)~0 >> 1));
	printf("signed short min =	%20d\n", -(short)((unsigned short)~0 >> 1)-1);
	printf("signed short max =	%20d\n", (short)((unsigned short)~0 >> 1));
	printf("signed int min =	%20d\n",   -(int)((unsigned int)~0 >> 1)-1);
	printf("signed int max =	%20d\n",   (int)((unsigned int)~0 >> 1));
	printf("signed long min =	%20ld\n",  -(long)((unsigned long)~0 >> 1)-1);
	printf("signed long max =	%20ld\n",  (long)((unsigned long)~0 >> 1));

	// calc unsigned types
	printf("\nunsigned types\n");
	printf("unsigned char max =	%20u\n",  (unsigned char)~0);
	printf("unsigned short max =	%20u\n", (unsigned short)~0);
	printf("unsigned int max =	%20u\n",   (unsigned int)~0);
	printf("unsigned long max =	%20lu\n", (unsigned long)~0);

	exit(0);
}