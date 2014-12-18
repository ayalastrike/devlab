#include	<stdio.h>
#include	<stdlib.h>

#define MAXLINE 	1000 	// 存储的行数的最大长度
#define EXCEED  	25		// 统计的字符长度阀值

int getLine(char[], int);

int main(int argc, char **argv)
{
	int len;
	char line[MAXLINE];

	while ( ( len = getLine(line, MAXLINE) ) >0 ) {
		if (len > EXCEED) {
			printf("The line exceed %d is %s", EXCEED, line);
		}
	}

	exit(0);
}

// 返回不超过 MAXLINE 的行数长度
int
getLine(char s[], int limit)
{
	int c, i;
	for ( i = 0; ( i<limit-1 ) && ( (c=getchar() ) != EOF && c !='\n' ); i++) {
		s[i] = c;
	}

	if(c == '\n') {
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	return i;
}