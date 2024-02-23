.global sumarr_ptr_s

# Sum an array of ints using pointers

# a0 - int arr[] (same as int *arr)
# a1 - int len

# t0 - int sum
# t1 - int i
# t2 - int tmp

sumarr_ptr_s:
    li t0, 0            # sum = 0
    li t1, 0            # i = 0

loop:
    bge t1, a1, done    
    lw t2, (a0)         # t2 = *arr
    add t0, t0, t2      # t0 (sum) = t0 (sum) + arr[i]
    addi a0, a0, 4      # a0 (arr) = a0 (arr) + 4 (next int in array)
    addi t1, t1, 1      # t1 (i) = t1 (i) + 1
    j loop

done:
    mv a0, t0           # a0 = t0 (sum)
    ret
