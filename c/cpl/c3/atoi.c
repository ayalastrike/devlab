#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int atoi2(char[]);

int
main(int argc, char **argv)
{

	char s[] = " -21";

	printf("%s\n", s);

	printf("%d\n", atoi2(s));

	exit(0);
}

int
atoi2(char s[])
{
	int i;

	// 跳过空白字符
	for (i = 0; isspace(s[i]); i++) {
		;
	}

	int sign = (s[i] == '-') ? -1 : 1;

	// 跳过正负号
	if ( s[i] == '+' || s[i] == '-' ) {
		i++;
	}

	int n;
	for (n = 0; isdigit(s[i]); i++) {
		n = 10 * n + (s[i] - '0');
	}
	n *= sign;
	return n;
}