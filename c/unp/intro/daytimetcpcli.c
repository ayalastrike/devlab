#include	"unp.h"

int
main(int argc, char **argv)
{
	int					sockfd, n;
	struct sockaddr_in	servaddr;
	char				receiveline[MAXLINE+1];

	if (argc != 2) {
		err_quit("usage: <Program> <IPaddress>");
	}

	if ( ( sockfd = socket(AF_INET, SOCK_STREAM, 0) ) < 0 ) {
		err_sys("socket error");
	}

	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(13);

	if ( inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
		err_sys("inet_pton error for %s", argv[1]);
	}

	printf("IPaddress: %s\n", argv[1]);
	printf("inet_pton: 0X%x  (%s)\n", servaddr.sin_addr.s_addr, judgeEndian());

	char serverIP[strlen(argv[1])+1];

	if ( inet_ntop(AF_INET, &servaddr.sin_addr, serverIP, sizeof(serverIP)) == NULL) {
		err_sys("inet_ntop error");
	}
	printf("inet_ntop: %s\n", serverIP);

	if ( connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) != 0 )	{
		err_sys("connect error");
	}

	while ( (n = read(sockfd, receiveline, MAXLINE) ) > 0) {
		receiveline[n] = '\0';
		if ( fputs(receiveline, stdout) == EOF ) {
			err_sys("fputs error");
		}
	} 

	if (n < 0) {
		err_sys("read error");
	}
	
	exit(0);
}