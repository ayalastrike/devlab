#include	<stdio.h>
#include	<stdlib.h>

#define MAXLINE 	1000 // 存储的行数的最大长度

int getLine(char[], int);
void copy(char[], char[]);

int
main(int argc, char **argv)
{
	char line[MAXLINE];
	char longest[MAXLINE];

	int len, max;
	max=0;

	while ( ( len=getLine(line, MAXLINE)) >0 ) {
		printf("len:%d %s", len, line);
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}

	if (max >0) {
		printf("the longest line is:%s\n", longest);
	} else {
		printf("No line is input.\n");
	}

	exit(0);
}

// 返回不超过 MAXLINE 的行数长度
int
getLine(char s[], int limit)
{
//	int i, c;
	int i, c, j;

	j = 0; // added j记录字符个数
//#	for(i=0; (i<limit-1) && (c=getchar())!=EOF && c!='\n'; ++i) {
	for ( i=0; ( c=getchar() ) != EOF && c!='\n'; ++i) {
		if ( i<limit-2 ) { // added  留两个位置给'\n', '\0'
			s[j] = c;
			j++;
		}
//		s[i] = c;
	}

	if (c=='\n') {
//		s[i] = c;
		s[j] = c; // added
		i++;
		j++; // added
	}
	s[i]='\0';
	return i;
}

// 拷贝字符串
void
copy(char d[], char s[])
{
	int i = 0;
	while ( (d[i] = s[i]) != '\0' ) {
		i++;
	}
}