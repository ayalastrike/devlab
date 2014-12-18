#include	"unp.h"

void
str_echo(int fd)
{
	ssize_t n;
	char	buff[MAXLINE];
	printf("hello from str_echo\n");

again:
	while ( ( n = read(fd, buff, MAXLINE)) > 0 ) {
		printf("n:%zu\n", n);
		Write(fd, buff, n);
	}


	if (n < 0 && errno == EINTR) {
		goto again;
	} else {
		err_sys("read error");
	}
}