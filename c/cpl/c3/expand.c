#include	<stdio.h>
#include	<stdlib.h>

void expand(char[], char[]);

int
main(int argc, char **argv)
{
	char s1[] = "-a-zX-Zbuzz-";

	char s2[100];

	printf("s1: %s\n", s1);
	expand(s1, s2);
	printf("s2: %s\n", s2);

	exit(0);
}

void
expand(char s1[], char s2[])
{
	char c;
	int i,j;

	i = j = 0;

	while ( (c = s1[i++]) != '\0' ) { // fetch a char from s1[]
		if ( s1[i] == '-' && s1[i+1] > c ) { // expand shorthand
			i++;
			while (c < s1[i]) {
				s2[j++] = c++;
			}
		} else {
			s2[j++] = c;					// just copy current char
		}
	}
	s2[j] = '\0';
}