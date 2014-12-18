#include	<stdio.h>
#include	<stdlib.h>

void appendAndEscape(char[], char[]);
void appendAndReverseEscape(char[], char[]);

int
main(int argc, char **argv)
{

	char str[] = "abcde";
	char appendStr[] = "x\ny\tz";

	printf("original str:%s\n", str);
	printf("append str:%s\n", appendStr);

	appendAndEscape(str, appendStr);

	printf("appended str:%s\n", str);

	char str2[] = "abcde";
	char appendStr2[] = "\\x\\ny\\tz";

	printf("original str:%s\n", str2);
	printf("append str:%s\n", appendStr2);

	appendAndReverseEscape(str2, appendStr2);

	printf("appended str:%s\n", str2);

	exit(0);
}

// 将字符串t复制到字符串s中，并将换行符和制表符体会为\n\t
void
appendAndEscape(char s[], char t[])
{
	int i;
	for (i=0; s[i] != '\0'; i++) {
		;
	}

	int j;
	for (j=0; t[j] != '\0'; j++) {
		switch ( t[j] ) {
			case '\n':
				s[i] = '\\';
				i++;
				s[i] = 'n';
				i++;
				break;
			case '\t':
				s[i] = '\\';
				i++;
				s[i] = 't';
				i++;
				break;
			default:
				s[i] = t[j];
				i++;
				break;
		}
	} 
	s[i] = '\0';
}

// 将字符串t复制到字符串s中，并将escape后的换行符和制表符体会为\n\t
void
appendAndReverseEscape(char s[], char t[])
{
	int i;
	for (i=0; s[i] != '\0'; i++) {
		;
	}

	int j;
	for (j=0; t[j] != '\0'; j++) {
		if ( t[j] != '\\' ) {
			s[i] = t[j];
			i++;
		} else {
			j++;
			switch ( t[j] ) {
				case 'n':
					s[i] = '\n';
					i++;
					break;
				case 't':
					s[i] = '\t';
					i++;
					break;
				default:
					s[i] = '\\';
					i++;
					s[i] = t[j];
					i++;
					break;
			}
		}
	} 
	s[i] = '\0';
}
