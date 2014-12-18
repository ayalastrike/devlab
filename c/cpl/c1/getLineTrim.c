#include	<stdio.h>
#include	<stdlib.h>

#define MAXLINE 	1000 // 存储的行数的最大长度

int getLine(char[], int);
int trim(char[]);

int
main(int argc, char **argv)
{
	int len;
	char line[MAXLINE];

	while ( ( len = getLine(line, MAXLINE) ) >0 ) {
		if ( trim(line) > 0 ) {
			printf("%s", line);
		}
	}

	exit(0);
}

// 返回不超过 MAXLINE 的行数长度
int
getLine(char s[], int limit)
{
	int c, i;
	for (i = 0; ( i<limit-1 ) && ( (c=getchar() ) != EOF && c !='\n' ); i++) {
		s[i] = c;
	}

	if(c == '\n') {
		s[i] = c;
		i++;
	}

	s[i] = '\0';

	return i;
}

// trim掉空格和tab，然后返回新的长度
int
trim(char s[])
{
	int i = 0;

	// 移动到换行符的前一个字符位置
	while ( s[i] != '\n' ) {
		i++;
	}
	i--;

	// 找到最后一个有效字符的位置
	while ( i>=0 && ( s[i] == ' ' || s[i] == '\t' ) ) {
		i--;
	}

	// 补上字符 \n \0
	if ( i >= 0 ) {
		i++;
		s[i] = '\n';
		i++;
		s[i] = '\0';
	}
	return i;
}