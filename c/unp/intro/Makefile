include ../Make.defines

PROGS = daytimetcpcli daytimetcpcli1 daytimetcpcli2 \
		daytimetcpsrv daytimetcpsrv1 daytimetcpsrv2 daytimetcpsrv3

all: ${PROGS}

daytimetcpcli: daytimetcpcli.o
	${CC} ${CFLAGS} -o $@ daytimetcpcli.o ${LIBS}

daytimetcpcli1: daytimetcpcli1.o
	${CC} ${CFLAGS} -o $@ daytimetcpcli1.o ${LIBS}

daytimetcpcli2: daytimetcpcli2.o
	${CC} ${CFLAGS} -o $@ daytimetcpcli2.o ${LIBS}

daytimetcpsrv: daytimetcpsrv.o
	${CC} ${CFLAGS} -o $@ daytimetcpsrv.o ${LIBS}

daytimetcpsrv1: daytimetcpsrv1.o
	${CC} ${CFLAGS} -o $@ daytimetcpsrv1.o ${LIBS}

daytimetcpsrv2: daytimetcpsrv2.o
	${CC} ${CFLAGS} -o $@ daytimetcpsrv2.o ${LIBS}

daytimetcpsrv3: daytimetcpsrv3.o
	${CC} ${CFLAGS} -o $@ daytimetcpsrv3.o ${LIBS}

clean:
	rm -f ${PROGS} ${CLEANFILES}