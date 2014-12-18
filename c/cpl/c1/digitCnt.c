#include <stdio.h>

int main() {

	int c, i, whiteCnt, othersCnt;
	int digit[10];

	whiteCnt = othersCnt = 0;

	for(i = 0; i<10; i++) {
		digit[i] = 0;
	}

	while((c=getchar())!=EOF) {
		if(c >='0' && c <= '9'){
			++digit[c-'0'];
		} else if (c ==' ' || c == '\t' || c == '\n') {
			whiteCnt++;
		} else {
			othersCnt++;
		}

	}

	printf("digits:");
	for(i = 0; i<10; i++) {
		printf(" %d", digit[i]);
	}

	printf(" while:%d others:%d\n", whiteCnt, othersCnt);

	return 1;
}
