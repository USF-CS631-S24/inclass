PROGS = decode signext
DECODE_OBJS = decode.o add2_s.o
SIGNEX_OBJS = signext.o

OBJS = $(DECODE_OBJS) $(SIGNEX_OBJS)

%.o: %.s
	as -g -o $@ $<

%.o: %.c
	gcc -c -g -o $@ $<

all : $(PROGS)

decode: $(DECODE_OBJS)
	gcc -g -o $@ $^

signext: $(SIGNEX_OBJS)
	gcc -g -o $@ $^


clean:
	rm -rf $(PROGS) $(OBJS)
