/* include unph */
/* Our own header.  Tabs are set for 4 spaces, not 8 */
#ifndef	__unp_h
#define	__unp_h


#include	<sys/types.h>	/* basic system data types */
#include	<sys/socket.h>	/* basic socket definitions */
#include	<netinet/in.h>	/* sockaddr_in{} and other Internet defns */
#include	<arpa/inet.h>	/* inet(3) functions */

#include	<stdio.h>
#include	<stdlib.h>
#include	<strings.h>
#include	<string.h>
#include	<unistd.h>
#include	<errno.h>

/* Miscellaneous constants */
#define	MAXLINE			4096	/* max text line length */
#define	BUFFSIZE		8192	/* buffer size for reads and writes */
#define IP_SIZE			128		/* Unix domain is largest */
#define PORT_SIZE		8 		/* port length */

#define ENDIAN_BIG		"big endian"		/* network character is big endian */
#define ENDIAN_LITTLE	"little endian"		/* network character is little endian */
#define ENDIAN_UNKNOWN	"unknown endian"	/* network character is unknown */

/* Define some port number that can be used for our examples */
#define	SERV_PORT		 9877			/* TCP and UDP */
#define	SERV_PORT_STR	"9877"			/* TCP and UDP */

/* Following shortens all the typecasts of pointer arguments: */
#define SA	struct sockaddr

/* Following could be derived from SOMAXCONN in <sys/socket.h>, but many
   kernels still #define it as 5, while actually supporting many more */
#define	LISTENQ		1024	/* 2nd argument to listen() */

/* prototypes for our socket wrapper functions: see {Sec errors} */
int 	Socket(int, int, int);
void 	Connect(int, const SA *, socklen_t);
void	Bind(int, const SA *, socklen_t);
void	Listen(int, int);
int 	Accept(int, SA *, socklen_t *);
void	Getsockname(int, SA *, socklen_t *);

/* prototypes for our Unix wrapper functions: see {Sec errors} */
void	Write(int, void *, size_t);
void	Close(int);

/* prototypes for our own library functions */
char	*judgeEndian(void);		/* lib/byteorder.c */
void	str_echo(int);			/* str_echo.c */
void	str_cli(FILE *, int);	/* str_cli.c */

char 	*Sock_ntop(const SA *, socklen_t);
char 	*sock_ntop(const SA *, socklen_t);

void	err_quit(const char *, ...);
void	err_sys(const char *, ...);

#endif	/* __unp_h */