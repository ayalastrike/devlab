#include	<stdio.h>
#include	<stdlib.h>

int binsearch(int, int[], int);

int
main(int argc, char** argv)
{
	int array[] = { 2, 1, 4, 76, 89, 3, 434, 11, 120 };

	int stopPos = 7; // stop at array[7] = 11

	int searchVal = 76;

	int i;
	int arrayLen = sizeof(array)/sizeof(array[0]);
	for (i = 0; i < arrayLen; i++) {
		printf("%4d ", array[i]);
		if (i == arrayLen-1) {
			printf("\n");
		}
	}


	printf("found val %d in scope %d: %d\n", searchVal, stopPos, binsearch(searchVal, array, stopPos));

	exit(0);
}

// 在 v[0] ~ v[n-1] 中使用二分查找法查找x，如果没有则返回-1
int
binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n-1;

	while (low <=high) {
		mid = (low+high) / 2;
		if (x < v[mid]) {
			high = mid - 1;
		} else if (x > v[mid]) {
			low = mid + 1;
		} else {
			return mid;
		}
	}
	return -1;
}