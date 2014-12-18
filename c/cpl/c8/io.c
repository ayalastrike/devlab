#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	"syscalls.h"



int
main(int argc, char **argv)
{
	char	buff[BUFFSIZE];
	int		n;

	while ( (n = read(0, buff, BUFFSIZE)) > 0 ) {
		printf("**read %d bytes**\n", n);
		write(1, buff, n);
	}

	exit(0);
}
