.global strcpy_s

# Copy the string at address src into the location at address dst
#
# a0 = char *dst
# a1 = char *src

# t0 = int i

strcpy_s:
    li t0, 0

# We are using array indexing by adding a0 + (i * 1), or a0 + i
for:
    add t1, a1, t0      # t1 = a1 + t0 (i)
    lb t2, (t1)         # t2 = src[t1]
    beq t2, zero, done  # is t2 == '\0'?
    add t3, a0, t0      # t3 = a0 + i
    sb t2, (t3)         # dst[t3] = t2
    addi t0, t0, 1      # t0 (i) = t0 (i) + 1
    j for
done:
    add t3, a0, t0      # t3 = a0 + t0 (i)
    sb zero, (t3)       # put '\0' at end of dst, dst[t3]
    ret
