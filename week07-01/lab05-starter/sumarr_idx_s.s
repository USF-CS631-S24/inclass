.global sumarr_idx_s

# Sum an array of ints using array indexing

# a0 - int arr[]
# a1 - int len

# t0 - int sum
# t1 - int i
# t2 - addr

sumarr_idx_s:
    li t0, 0            # sum = 0
    li t1, 0            # i = 0

loop:
    bge t1, a1, done    
    li t2, 4            # t2 = 4
    mul t2, t1, t2      # t2 = i * 4
    add t2, a0, t2      # t2 = a0 + (i * 4)
    lw t2, (t2)         # t4 = arr[i]
    add t0, t0, t2      # t0 (sum) = t0 (sum) + arr[i]
    addi t1, t1, 1      # t1 (i) = t1 (i) + 1
    j loop

done:
    mv a0, t0           # a0 = t0 (sum)
    ret
