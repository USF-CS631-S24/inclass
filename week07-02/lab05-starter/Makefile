PROG = lab05
OBJS = lab05.o rv_emu.o\
	   add2_c.o add2_s.o\
	   quadratic_c.o quadratic_s.o\
	   max3_c.o max3_s.o\
       get_bitseq_c.o get_bitseq_s.o\
       midpoint_c.o midpoint_s.o\
       sumarr_idx_c.o sumarr_idx_s.o
       
HEADERS = rv_emu.h bits.h

CFLAGS = -g -Wall

%.o : %.c $(HEADERS)
	gcc $(CFLAGS) -c -o $@ $<

%.o : %.s
	as -g -o $@ $<

all : $(PROG)

$(PROG) : $(OBJS)
	gcc $(CFLAGS) -o $@ $(OBJS)

clean :
	rm -rf $(PROG) $(OBJS)
