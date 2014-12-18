#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

int trim(char[]);

int
main(int argc, char **argv)
{
	char str[] = "abcde  	";

	printf("strlen:%zu str:%s\n", strlen(str), str);
	trim(str);
	printf("strlen:%zu str:%s\n", strlen(str), str);

	exit(0);
}

int trim(char s[])
{
	int n;
	for (n = strlen(s)-1; n >= 0; n--) {
		if ( s[n] != '\n' && s[n] !='\t' && s[n] !=' ' ) {
			break;
		}

	}
	// 注意+1补\0
	s[n+1] = '\0';

	return n;
}

