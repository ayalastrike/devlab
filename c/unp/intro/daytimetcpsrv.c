#include	"unp.h"
#include	<time.h>

int
main(int argc, char **argv)
{
	int					listenfd, connfd;
	struct sockaddr_in	servaddr, cli;
	time_t				ticks;
	char				buff[MAXLINE];
	
	listenfd = Socket(AF_INET, SOCK_STREAM, 0);
	printf("listenfd: %d\n", listenfd);

	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(13);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	if ( bind(listenfd, (SA *)&servaddr, sizeof(servaddr)) == -1) {
		err_sys("bind error");
	}

	if ( listen(listenfd, 1024) == -1) {
		err_sys("listen error");
	}

	for( ; ; ) {
		if ( (connfd = accept(listenfd, (SA *)NULL, NULL)) == -1 ) {
			err_sys("accept error");
		}
		printf("connfd: %d\n", connfd);

		ticks = time(NULL);
		snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));

		if ( write(connfd, buff, MAXLINE) != MAXLINE) {
			err_sys("write error");
		}

		if ( close(connfd) == -1 ) {
			err_sys("close error");
		}
	}

	exit(0);
}