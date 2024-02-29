.global get_bitseq_s

# a0 - uint32_t num
# a1 - int start
# a2 - int end

# t0 - uint32_t val
# t1 - int len
# t2 - uint32_t mask

get_bitseq_s:
    sub t1, a2, a1      # t1 (len) = a2 (end) - a1 (start)
    addi t1, t1, 1      # t1 (len) = t1 (len) + 1
    srlw t0, a0, a1     # t0 (val) = a0 (num) >> a1 (start)

    li t3, 32           # t3 = 32
    bne t1, t3, else    # is t1 (len) == 32?
    li t3, 0xFFFFFFFF   # t2 (mask) = 0xFFFFFFFF
    j done
else:
    li t3, 1            # t3 (mask) = 1
    sllw t3, t3, t1     # t3 (mask) = 1 << t1 (len)
    addi t3, t3, -1     # t3 (mask) = t3 (mask) - 1
done:    
    and a0, t0, t3      # a0 = t0 (val) & t3 (mask)
    ret
