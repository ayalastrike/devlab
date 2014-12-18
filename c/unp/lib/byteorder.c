#include	"unp.h"

char
*judgeEndian(void)
{
	union {
		short	s;
		char	c[sizeof(short)];
	} un;

	un.s = 0X0102;

	if ( sizeof(short) == 2 ) {
		if ( un.c[0] == 1 && un.c[1] == 2 ) {
			return ENDIAN_BIG;
		} else if ( un.c[0] == 2 && un.c[1] == 1) {
			return ENDIAN_LITTLE;
		}
	} else {
		return ENDIAN_UNKNOWN;
	}

	return ENDIAN_UNKNOWN;
}