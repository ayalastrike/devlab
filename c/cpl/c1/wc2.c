#include	<stdio.h>
#include	<stdlib.h>

#define IN 		1 // 当前字符在单词之内
#define OUT 	0 // 当前字符在单词之外

int
main(int argc, char **argv)
{
	int c, state;
	int nl;		// 行数
	int nw;		// 单词数
	int nc;		// 字符数

	nl = nw = nc = 0;
	state = OUT;

	while( (c=getchar()) != EOF) {
		nc++;
		if (c == '\n') {
			nl++;
		}

		if (c == ' ' || c == '\n' || c == '\t'){
			state = OUT;
		} else if (state == OUT) {
			putchar('\n');
			putchar(c);
			state = IN;
			nw++;
		} else if (state == IN) {
			putchar(c);
		}
	}

	printf("\n");
	printf("nl:%d\n", nl);
	printf("nw:%d\n", nw);
	printf("nc:%d\n", nc);

	exit(0);
}
