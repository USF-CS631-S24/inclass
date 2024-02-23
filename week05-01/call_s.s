.global foo_s

# This is an example of how to call a function from
# an assembly function.

# If you call a function you need to preserve the RA
# register.

bar_s:
    addi a0, a0, 1
    ret

foo_s:
    addi sp, sp, -16    # Allocate 16 bytes of stack space.
                        # The sp needs to be a multiple of 16.
                        # Even if we do not use all 16 bytes
                        # 
    sd ra, (sp)         # Preserve ra

    call bar_s          # ra = PC + 4
    addi a0, a0, 1

    ld ra, (sp)         # Restore ra
    addi sp, sp, 16     # Deallocate 16 bytes
    ret
