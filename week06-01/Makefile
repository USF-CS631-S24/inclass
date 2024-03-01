PROGS = endian hello_s twos strlen strcpy bits get_bitseq intdr sumarr_idx_s

ENDIAN_OBJS = endian.o
HELLOS_OBJS = hello_s.o
TWOS_OBJS   = twos.o
STRLEN_OBJS = strlen.o strlen_c.o strlen_s.o
STRCPY_OBJS = strcpy.o strcpy_c.o strcpy_s.o
BITS_OBJS   = bits.o bits_s.o
GBS_OBJS    = get_bitseq.o get_bitseq_c.o get_bitseq_s.o
INTDR_OBJS  = intdr.o intdr_c.o intdr_s.o
SUMARR_IDX_OBJS = sumarr_idx_s.o

OBJS = $(ENDIAN_OBJS) $(HELLOS_OBJS) $(TWOS_OBJS) \
       $(STRLEN_OBJS) $(STRCPY_OBJS) $(BITS_OBJS) \
       $(GBS_OBJS) $(INTDR_OBJS) $(SUMARR_IDX_OBJS)

%.o: %.s
	as -g -o $@ $<

%.o: %.c
	gcc -c -g -o $@ $<

all: $(PROGS)

endian: $(ENDIAN_OBJS)
	gcc -g -o $@ $^

hello_s: $(HELLOS_OBJS)
	gcc -g -o $@ $^

twos: $(TWOS_OBJS)
	gcc -g -o $@ $^

strlen: $(STRLEN_OBJS)
	gcc -g -o $@ $^

strcpy: $(STRCPY_OBJS)
	gcc -g -o $@ $^

bits: $(BITS_OBJS)
	gcc -g -o $@ $^

get_bitseq: $(GBS_OBJS)
	gcc -g -o $@ $^

intdr: $(INTDR_OBJS)
	gcc -g -o $@ $^

sumarr_idx_s: $(SUMARR_IDX_OBJS)
	gcc -g -o $@ $^

clean:
	rm -rf $(PROGS) $(OBJS)
