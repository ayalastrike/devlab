#include	"unp.h"

char
*sock_ntop(const struct sockaddr *sa, socklen_t len)
{
	char port[PORT_SIZE];
	static char str[IP_SIZE];

	switch (sa->sa_family) {
		case AF_INET: {

			// cast to sockaddr_in
			struct sockaddr_in *sin = (struct sockaddr_in *)sa;

			if ( inet_ntop(AF_INET, &sin->sin_addr, str, sizeof(str)) == NULL) {
				return NULL;
			}

			if (ntohs(sin->sin_port) != 0) {
				snprintf(port, sizeof(port), ":%d", ntohs(sin->sin_port));
				strcat(str, port);
			}

			return str;
		}
		default: {
			snprintf(str, sizeof(str), "sock_ntop: unknown AF_XXX %d, len %d", sa->sa_family, len);
		}
	}
	return NULL;
}

char
*Sock_ntop(const struct sockaddr *sa,  socklen_t len)
{
	char *ptr;
	if ( ( ptr = sock_ntop(sa, len)) == NULL) {
		err_sys("sock_ntop error");
	}

	return ptr;
}