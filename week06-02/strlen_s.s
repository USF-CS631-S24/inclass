.global strlen_s

# Compute the lenght of the string starting at address a0
#
# a0 - char *s

# t0 - int len

strlen_s:
    li t0, 0             # t0 (len) = 0

# We are using a pointer approach to walking through the array
while:
    lb t1, (a0)          # t1 = *a0
    beq t1, zero, done   # is t1 == '\0'?
    addi t0, t0, 1       # t1 (len) = t1 (len) + 1
    addi a0, a0, 1       # a0 = a0 + 1 <-- go to next byte in array s
    j while

done:
    mv a0, t0            # put t0 (len) into a0 (return value)
    ret
