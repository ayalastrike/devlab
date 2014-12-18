#include	<stdio.h>
#include	<stdlib.h>

#define MAXLINE 	1000 // 存储的行数的最大长度

int getLine(char[], int);
void reverse(char[]);

int
main(int argc, char **argv)
{
	int len;
	char line[MAXLINE];

	while ( ( len = getLine(line, MAXLINE) ) >0 ) {
		reverse(line);
		printf("%s", line);
	}

	exit(0);
}

// 返回不超过 MAXLINE 的行数长度
int
getLine(char s[], int limit) {
	int c, i;
	for ( i = 0; (i<limit-1) && ( (c=getchar() ) != EOF && c != '\n' ); i++) {
		s[i] = c;
	}

	if ( c == '\n' ) {
		s[i] = c;
		i++;
	}

	s[i] = '\0';
	printf("line:%s", s);
	return i;
}

// 反转字符串
void
reverse(char s[])
{
	int i = 0, j = 0;

	// 移动到换行符的前一个字符位置
	while ( s[i] != '\0' ) {
		i++;
	}
	i--;

	// 移动到换行符之前
	if ( s[i] == '\n' ) {
		i--;
	}

	// 反转
	while ( j < i ) {
		char tmp = s[j];
		s[j] = s[i];
		s[i] = tmp;
		i--;
		j++;
	}
}