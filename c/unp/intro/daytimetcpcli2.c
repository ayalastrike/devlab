#include	"unp.h"

int
main(int argc, char **argv)
{
	int					sockfd, n, counter = 0;
	struct sockaddr_in	servaddr, cliaddr;
	char				receiveline[MAXLINE+1];

	if (argc != 2) {
		err_quit("usage: <Program> <IPaddress>");
	}

	sockfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(13);

	if ( inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
		err_sys("inet_pton error for %s", argv[1]);
	}

	printf("IPaddress: %s\n", argv[1]);
	printf("inet_pton: 0X%x  (%s)\n", servaddr.sin_addr.s_addr, judgeEndian());

	char serverIP[IP_SIZE];

	if ( inet_ntop(AF_INET, &servaddr.sin_addr, serverIP, sizeof(serverIP)) == NULL) {
		err_sys("inet_ntop error");
	}
	printf("inet_ntop: %s\n", serverIP);

	Connect(sockfd, (SA *) &servaddr, sizeof(servaddr));

	// get client socket addr
	socklen_t clilen = sizeof(cliaddr);
	Getsockname(sockfd, (SA *)&cliaddr, &clilen);

	printf("client: [ %s ]\n", Sock_ntop((SA *)&cliaddr, sizeof(cliaddr)));

	while ( (n = read(sockfd, receiveline, MAXLINE) ) > 0) {
		counter++;
		receiveline[n] = '\0';
		if ( fputs(receiveline, stdout) == EOF ) {
			err_sys("fputs error");
		}
	} 

	if (n < 0) {
		err_sys("read error");
	}

	printf("counter: %d\n", counter);
	
	exit(0);
}