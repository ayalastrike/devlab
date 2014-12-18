#include	"unp.h"

int
Socket(int family, int type, int protocol)
{
	int fd;
	if ( ( fd = socket(family, type, protocol) ) < 0 ) {
		err_sys("socket error");
	}

	return fd;
}

void
Connect(int fd, const struct sockaddr *sa, socklen_t len)
{
	if ( connect(fd, sa, len) == -1 ) {
		err_sys("connect error");
	}
}

void
Bind(int fd, const struct sockaddr *sa, socklen_t len)
{
	if ( bind(fd, sa, len) == -1) {
		err_sys("bind error");
	}
}

void
Listen(int fd, int backlog)
{
	/* override witn environment variable */
	char *ptr;
	if ( (ptr = getenv("LISTENQ")) != NULL) {
		backlog = atoi(ptr);
	}

	if ( listen(fd, backlog) == -1) {
		err_sys("listen error");
	}
}

int
Accept(int fd, struct sockaddr *sa, socklen_t *len)
{
	int n;
	if ( (n = accept(fd, sa, len)) == -1 ) {
		err_sys("accept error");
	}
	return n;
}

void
Getsockname(int fd, struct sockaddr *sa, socklen_t *len)
{
	if ( getsockname(fd, sa, len) == -1) {
		err_sys("getsockname error");
	}
}