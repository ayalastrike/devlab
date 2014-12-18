#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

void reverse(char[]);

int
main(int argc, char **argv)
{
	char str[] = "abcde";

	printf("%s\n", str);
	reverse(str);
	printf("%s\n", str);

	exit(0);
}

void
reverse(char s[])
{
	int tmp, i, j;
	for(i=0, j = strlen(s)-1; i<j; i++, j--) {
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
}