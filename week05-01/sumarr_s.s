.global sumarr_s

# a[] - a0
# len - a1
# sum - t0
# i   - t1

sumarr_array_s:
    li t0, 0            # sum = 0
    li t1, 0            # i = 0

loop:
    bge t1, a1, done    
    li t2, 4            # t2 = 4
    mul t3, t1, t2      # t3 = i * 4
    add t4, a0, t3      # t4 = a0 + (i * 4)
    lw t4, (t4)         # t4 = arr[i]
    add t0, t0, t4      # sum = sum + arr[i]
    addi t1, t1, 1      # i = i + 1
    j loop

done:
    mv a0, t0           # a0 = sum
    ret

# sumarr_ptr_s

sumarr_s:
    li t0, 0            # sum = 0
    li t1, 0            # i = 0

ptr_loop:
    bge t1, a1, ptr_done    
    lw t2, (a0)         # t2 = *a0
    add t0, t0, t2      # sum = sum + *a0
    addi a0, a0, 4      # a0 = a0 + 4
    addi t1, t1, 1      # i = i + 1
    j ptr_loop

ptr_done:
    mv a0, t0           # a0 = sum
    ret
