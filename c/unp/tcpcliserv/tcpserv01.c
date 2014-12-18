#include	"unp.h"

int
main(int argc, char **argv)
{
	int					listenfd, connfd;
	struct sockaddr_in	servaddr, cliaddr;
	socklen_t 			clilen;
	pid_t				childpid;

	listenfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(INADDR_ANY);
	servaddr.sin_addr.s_addr = htonl(SERV_PORT);

	Bind(listenfd, (SA *)&servaddr, sizeof(servaddr));

	Listen(listenfd, LISTENQ);

	for ( ; ; ) {
		clilen = sizeof(cliaddr);
		connfd = Accept(listenfd, (SA *)&cliaddr, &clilen);

		printf("accepted client [ fd %d ] [ %s ]\n", connfd, Sock_ntop( (SA *)&cliaddr, sizeof(cliaddr)));

		if ( (childpid = fork()) == 0) { /* child process */
			Close(listenfd);
			str_echo(connfd);
			exit(0);
		}
		
		Close(connfd); /* parent process */
	}

	exit(0);
}