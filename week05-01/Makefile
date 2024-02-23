PROGS = call add4f arr inrange factrec
SUMARR_OBJS = sumarr.o sumarr_idx_c.o sumarr_ptr_c.o \
			  sumarr_idx_s.o sumarr_ptr_s.o
CALL_OBJS = call.o call_c.o call_s.o
ADD4F_OBJS = add4f.o add4f_c.o add4f_s.o add4f_callee_s.o
ARR_OBJS = arr.o arr_c.o arr_s.o
INRANGE_OBJS = inrange.o inrange_c.o inrange_s.o
FACTREC_OBJS = factrec.o factrec_c.o factrec_s.o

%.o: %.s
	as -g -o $@ $<

%.o: %.c
	gcc -c -g -o $@ $<

all: $(PROGS)

sumarr: $(SUMARR_OBJS)
	gcc -g -o $@ $^

call: $(CALL_OBJS)
	gcc -g -o $@ $^

add4f: $(ADD4F_OBJS)
	gcc -g -o $@ $^

arr: $(ARR_OBJS)
	gcc -g -o $@ $^

inrange: $(INRANGE_OBJS)
	gcc -g -o $@ $^

factrec: $(FACTREC_OBJS)
	gcc -g -o $@ $^

	
clean:
	rm -rf $(PROGS) $(CALL_OBJS) $(ADD4F_OBJS) $(ARR_OBJS) \
	       $(INRANGE_OBJS) $(FACTREC_OBJS)
