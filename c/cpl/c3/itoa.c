#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

void itoa(int, char[]);
void reverse(char[]);

int
main(int argc, char **argv)
{
	int number = -4278;
	char str[100];

	printf("%d\n", number);
	itoa(number, str);
	printf("%s\n", str);

	exit(0);
}

void
itoa(int n, char s[])
{
	int i, sign;

	if ( ( sign = n ) < 0 ) {
		n = -n;
	}

	i = 0;
	do {
		s[i] = n % 10 + '0';
		i++;
	} while ( (n/=10) > 0 );

	if (sign < 0) {
		s[i++] = '-';
	}
	s[i] = '\0';

	reverse(s);
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