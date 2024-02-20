PROG = lab02
OBJS = scan.o parse.o
HEADERS = ntlang.h

CFLAGS = -g

# Pattern rules to avoid explicit rules
%.o : %.c ${HEADERS}
	gcc ${CFLAGS} -c -o $@ $<

all : ${PROG}

lab02 : ${PROG}.c ${HEADERS} ${OBJS}
	gcc ${CFLAGS} -o $@ $< ${OBJS}

clean :
	rm -rf ${PROG} ${OBJS}
