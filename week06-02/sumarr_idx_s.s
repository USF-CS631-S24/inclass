.global main
.global sumarr_idx_s
.global printf

.data

sumarr_out_str:
    .string "sumarr_idx_s() = %d\n"

.text

main:
    addi sp, sp, -16
    sd ra, (sp)

    addi sp, sp, -32

    li t0, 1
    sw t0, 0(sp)
    li t0, 2
    sw t0, 4(sp)
    li t0, 3
    sw t0, 8(sp)
    li t0, 4
    sw t0, 12(sp)
    li t0, 5
    sw t0, 16(sp)

    mv a0, sp
    li a1, 5
    call sumarr_idx_s

    mv a1, a0
    la a0, sumarr_out_str
    call printf

    addi sp, sp, 32

    ld ra, (sp)
    addi sp, sp, 16
    ret


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
