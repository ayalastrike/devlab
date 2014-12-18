#include	<stdio.h>
#include	<stdlib.h>

#define IN 					1 	// 当前字符在单词之内
#define OUT 				0 	// 当前字符在单词之外
#define MAX_WORD_LENGTH 	11  // 统计的单词最大长度
#define MAX_WORD_GRAPHIC 	15 	// 直方图中的*显示长度

int
main(int argc, char **argv)
{

	int c, state, i;
	int nc; 			// 单词长度
	int overflow;		// 超过统计长度 MAX_WORD_LENGTH 的单词的数量
	int j;				// 直方图显示使用
	int maxvalue;		// 出现次数最多的单词次数
	
	state = OUT;
	nc = 0;
	overflow = 0;

	// 单词长度频度数组 wl[]
	int wl[MAX_WORD_LENGTH];

	for (i=0; i<MAX_WORD_LENGTH; i++) {
		wl[i] = 0;
	}

	while ( (c = getchar()) != EOF ) {
		if ( c == ' ' || c == '\n' || c == '\t' ) {
			// 单词分割中
			state = OUT;

			if (nc > 0) {
				if( nc < MAX_WORD_LENGTH) {
					wl[nc]++;
				} else {
					overflow++;
				}
			}
			nc = 0;
		} else if (state == OUT) {
			// 进入单词首字母
			state = IN;
			putchar('\n');
			putchar(c);

			nc = 1;
		} else if (state == IN) {
			// 在单词字母中
			putchar(c);
			nc++;
		}
	}

	// 出现次数最多的单词次数 maxvalue
	maxvalue = 0;
	for (i=1; i< MAX_WORD_LENGTH; i++) {
		if ( wl[i] > maxvalue ) {
			maxvalue = wl[i];
		}
	}

	printf("\nmaxvalue: %d\n", maxvalue);

	for (i=MAX_WORD_GRAPHIC; i>0; --i) {
		for (j=1; j< MAX_WORD_LENGTH; ++j){
			if ( wl[j] * MAX_WORD_GRAPHIC / maxvalue >= i ) {
				printf("   * ");
			} else {
				printf("     ");
			}
		}
		putchar('\n');
	}

	for (i=1; i< MAX_WORD_LENGTH; i++) {
		printf("%4d ", i);
	}
	putchar('\n');

	for (i=1; i< MAX_WORD_LENGTH; i++) {
		printf("%4d ", wl[i]);
	}
	putchar('\n');

	if (overflow > 0) {
		printf("There are %d words >= %d\n", overflow, MAX_WORD_LENGTH);
	}

	exit(0);
}
