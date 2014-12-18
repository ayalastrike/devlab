#include	<stdio.h>
#include	<stdlib.h>

int any(char[], char[]);

int
main(int argc, char **argv)
{
	char s1[] = "abcdefghijklmn";

	char s2[] = "xyzg";

	printf("s1:%s\n", s1);
	printf("s2:%s\n", s2);
	printf("occur pos:%d\n", any(s1, s2));

	exit(0);
}

// 返回s1中首次出现字符串s2的位置，如果不存在，则返回-1
int
any(char s1[], char s2[])
{
	int i, j;
	for ( i=0; s1[i] != '\0'; i++) {
		for (j=0; s2[j] != '\0'; j++) {
			if ( s1[i] == s2[j] ) {
				return i;
			}
		}
	}

	return -1;
}