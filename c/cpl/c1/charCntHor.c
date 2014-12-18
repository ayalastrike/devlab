#include	<stdio.h>
#include	<ctype.h>
#include	<stdlib.h>

#define IN 					1  	// 当前字符在单词之内
#define OUT 				0 	// 当前字符在单词之外
#define MAX_CHAR_LENGTH 	128 // 统计的单词最大长度
#define MAX_CHAR_GRAPHIC 	15 	// 直方图中的*显示长度

int
main(int argc, char **argv)
{
	int c, i;
	int nc;			// 统计长度 MAX_CHAR_LENGTH 内的字符的数量
	int overflow;	// 超过统计长度 MAX_CHAR_LENGTH 的字符的数量
	int maxvalue;	// 字符出现最多的次数
	int len;      	// 打印的直方图中*的数量
	
	nc = 0;
	overflow = 0;

	// 初始化字符统计数组wl[]
	int wl[MAX_CHAR_LENGTH];
	
	for (i=0; i<MAX_CHAR_LENGTH; i++) {
		wl[i] = 0;
	}

	while( (c = getchar()) != EOF) {
//		if( c >= 'a' && c <='z') {
		if(c < MAX_CHAR_LENGTH) {
			wl[c]++;
			nc++;
		} else {
			overflow++;
		}

	}

	// 找出字符出现最多的次数 maxvalue
    maxvalue = 0;
	for (i=1; i< MAX_CHAR_LENGTH; i++) {
		if (wl[i] > maxvalue) {
			maxvalue = wl[i];
		}
	}

	printf("maxvalue: %d\n", maxvalue);
	printf("char count: %d\n", nc);
	for (i=1; i< MAX_CHAR_LENGTH; i++) {
		if ( isprint(i) ) {
			printf("%5d - %c - %5d :", i, i, wl[i]);
		} else {
			printf("%5d -  - %5d :", i, wl[i]);
		}

		if ( wl[i] > 0 ) {
			if ( (len = wl[i] * MAX_CHAR_GRAPHIC / maxvalue) <=0 ) {
				len = 1;
			}
		} else {
			len = 0;
		}

		while (len > 0) {
			putchar('*');
			len--;
		}
		putchar('\n');
	}

	if (overflow > 0) {
		printf("There are %d words >= %d\n", overflow, MAX_CHAR_LENGTH);
	} else {
		printf("There is no character out of scope (%d).\n", MAX_CHAR_LENGTH);
	}

	exit(0);
}
