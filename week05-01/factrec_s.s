.global factrec_s

# Compute !n using a recursive approach

# a0 - int n

factrec_s:
    addi sp, sp, -16
    sd ra, (sp)

    # Base case
    bgt a0, zero, recstep
    li a0, 1
    j done

    # Recursive step
recstep:

    sd a0, 8(sp)        # Preserve a0 (n) on stack
    addi a0, a0, -1

    call factrec_s

    ld t0, 8(sp)        # Restore a0 (n) from stack
    mul a0, a0, t0      # a0 = factrect(n-1) * n

done:
    ld ra, (sp)
    addi sp, sp, 16
    ret

