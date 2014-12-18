#include	<stdio.h>
#include	<ctype.h>
#include	<stdlib.h>

#define NO 		0
#define YES		1

// There is duplicate atoi in stdlib.h, so rename the implement functions
int atoi2(char[]);
int htoi2(char[]);

int
main(int argc, char **argv)
{

	char s[] = "1234a";

	printf("%s\n", s);
	printf("atoi():%d\n", atoi2(s));
	printf("htoi():%d\n", htoi2(s));

	exit(0);
}

// 字符串转10进制数
int
atoi2(char s[])
{
	int i, n;
	n=0;
	for (i=0; isdigit(s[i]); i++) {
		n = 10*n + ( s[i]-'0' );
	}

	return n;
}

// 16进制转10进制
int
htoi2(char s[])
{
	int i, n, hex, inhex;

	i = 0;

	// 移动到有效的十六进制字符位置
	if (s[i] == '0') {
		i++;
		if ( s[i] == 'X' || s[i] == 'x' ) {
			i++;
		}
	}

	n=0;
	inhex = YES;

	for(; inhex == YES; i++) {
		if ( isdigit(s[i]) ) {
			hex = s[i] - '0';
		} else if ( s[i] >= 'A' && s[i] <= 'F' ) {
			hex = s[i] - 'A' + 10;
		} else if ( s[i] >= 'a' && s[i] <= 'f' ) {
			hex = s[i] - 'a' + 10;
		} else {
			inhex = NO;
		}
		
		if ( inhex == YES ) {
			n = 16*n + hex;
		}
	}

	return n;
}