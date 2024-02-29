.global intdr_s

# a0 = int *pos

intdr_s:
    lw t0, (a0)      # t0 = *pos
    addi t0, t0, 1   # t0 = t0 + 1
    sw t0, (a0)      # *pos = t0
    ret
    
