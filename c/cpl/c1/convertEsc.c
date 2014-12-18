#include	<stdio.h>
#include	<stdlib.h>

int main(int argc, char **argv)
{

	double blankCnt, tabCnt, lineCnt;

	blankCnt = 0;
	tabCnt = 0;
	lineCnt = 0;

	int c;

	while( ( c=getchar()) != EOF ) {
		switch (c) {
			case ' ':
				blankCnt++;
				printf("\\b");
				break;
			case '\t':
				tabCnt++;
				printf("\\t");
				break;
			case '\\':
				printf("\\\\");
				break;
			case '\n':
				lineCnt++;
				putchar(c);
				break;
			default:
				putchar(c);
				break;
		}
	}

	printf("blank count:%.0f\n", blankCnt);
	printf("tab count:%.0f\n", tabCnt);
	printf("line count:%.0f\n", lineCnt);

	exit(0);
}
