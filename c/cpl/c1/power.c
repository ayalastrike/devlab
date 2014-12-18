#include	<stdio.h>
#include	<stdlib.h>

int power(int, int);

int
main(int argc, char **argv)
{
	int i;
	for (i=0; i<10; i++) {
		printf("阶数:%3d   power(0, i):%8d   power(2, i):%8d   power(-3, i):%8d\n", i, power(0, i), power(2, i), power(-3, i));
	}

	exit(0);
}

// base		底数
// guade	阶数
int
power(int base, int guade)
{
	int p, i;

	// 阶乘运算最小结果为1，所以初始值设为1
	p = 1;
	for (i=1; i <= guade; i++) {
		p *= base;
	}

	return p;
}