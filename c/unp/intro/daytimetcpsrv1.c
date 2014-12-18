#include	"unp.h"
#include	<time.h>

int
main(int argc, char **argv)
{
	int					listenfd, connfd;
	struct sockaddr_in	servaddr;
	time_t				ticks;
	char				buff[MAXLINE];
	
	listenfd = Socket(AF_INET, SOCK_STREAM, 0);
	printf("listenfd: %d\n", listenfd);

	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(13);
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	Bind(listenfd, (SA *)&servaddr, sizeof(servaddr));

	Listen(listenfd, LISTENQ);

	for( ; ; ) {
		connfd = Accept(listenfd, (SA *)NULL, NULL);
		printf("connfd: %d\n", connfd);

		ticks = time(NULL);
		snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));

		Write(connfd, buff, strlen(buff));

		Close(connfd);
	}

	exit(0);
}