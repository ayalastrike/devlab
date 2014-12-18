#include	<stdio.h>
#include	<stdlib.h>

void shellsort(int[], int);
void printArray(int[], int);

int
main(int argc, char **argv)
{
	int array[] = {5, 34, 23, 4, 345, 7, 20};

	int arraySize = sizeof(array) / sizeof(array[0]);

	printArray(array, arraySize);

	shellsort(array, arraySize);

	printArray(array, arraySize);

	exit(0);
}

void
shellsort(int v[], int n)
{
	int gap, i, j, tmp;

	for (gap = n/2; gap > 0; gap /=2) {
		for (i=gap; i<n; i++) {
			for (j = i-gap; j >= 0 && v[j] > v[j+gap]; j-=gap) {
				tmp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = tmp;
			}
		}
	}
}

void printArray(int v[], int n)
{
	int i;
	for (i = 0; i<n; i++) {
		printf("%4d ", v[i]);
		if (i == n-1) {
			printf("\n");
		}
	} 

}