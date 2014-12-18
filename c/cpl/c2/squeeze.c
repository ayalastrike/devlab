#include	<stdio.h>
#include 	<stdlib.h>

void squeeze(char[], char);
void squeeze2(char[], char[]);

int
main(int argc, char **argv)
{
	char s[] = "abcdefg";
	char t[] = "ef";
	char c = 'b';

	printf("%s delete %c:\n", s, c);

	squeeze(s, c);

	printf("%s\n", s);

	printf("\n%s delete %s:\n", s, t);
	squeeze2(s, t);
	printf("%s\n", s);

	exit(0);
}

// 删除掉字符串s中出现的字符c
void
squeeze(char s[], char c)
{
	int i, j;

	// i表示当前指针, 在for循环中始终++
	// j表示处理后的指针, 只有处理后，才++
	for ( i=j=0; s[i] != '\0'; i++) {
		if ( s[i] != c ) {
			s[j++] = s[i];
			// 等价于
			// s[j] = s[i];
			// j++;
		}
	}

	s[j] = '\0';
}

// 删除掉字符串s1中出现的字符串s2
void
squeeze2(char s1[], char s2[])
{
	int i, j, k;

	// i表示s1当前指针, 在for循环中始终++
	// j表示s2当前指针, 在s2[j] == s1[i]或者末尾处停止
	// k只有在匹配时移动指针++
	for ( i=k=0; s1[i] != '\0'; i++) {
		for ( j=0; s2[j] != '\0' && s2[j] != s1[i]; j++) 
			;
		// 如果没有找到匹配字符，s[j]就会移动到\0，在这时再进行s1赋值即可
		if ( s2[j] == '\0' ) {
			s1[k++] = s1[i];
		}
	}
	s1[k] = '\0';
}