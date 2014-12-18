#include	"unp.h"

int
main(int argc, char **argv)
{
	int sockfd;

	struct sockaddr_in servaddr;

	if (argc != 2) {
		err_sys("usage: <Program> <IPaddress>");
	}

	sockfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	if ( inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
		err_sys("inet_pton error for %s", argv[1]);
	}

	Connect(sockfd, (SA *) &servaddr, sizeof(servaddr));

	exit(0);
}