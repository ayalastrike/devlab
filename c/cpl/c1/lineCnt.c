#include	<stdio.h>
#include	<stdlib.h>

int
main(int argv, char **argc) {

	double blankCnt, tabCnt, lineCnt;

	blankCnt = 0;
	tabCnt = 0;
	lineCnt = 0;

	int c;

	while( (c=getchar()) != EOF ) {
		switch (c) {
			case ' ':
				blankCnt++;
				break;
			case '\t':
				tabCnt++;
				break;
			case '\n':
				lineCnt++;
				break;
			default:
				break;

		}
	}

	printf("blank count:%.0f\n", blankCnt);
	printf("tab count:%.0f\n", tabCnt);
	printf("line count:%.0f\n", lineCnt);

	exit(0);
}
