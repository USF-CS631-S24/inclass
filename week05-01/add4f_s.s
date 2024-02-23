.global add4f_s

# Add two args
#
# a0 - int a
# a1 - int b
add2_s:
    add a0, a0, a1
    ret

# Add four args using 3 calls to add2_s
#
# a0 - int a
# a1 - int b
# a2 - int c
# a3 - int d

# We use a caller-saved register approach.
# This means that before we make a call,
# we save any caller-saved registers we need
# to preserve on the stack (a0-a7,t0-t6),
# and restore them after the call.

add4f_s:
    addi sp, sp, -32 # Must be a multiple 16
    sd ra, (sp)      # Preserve ra on stack

    # a0 and a1 already set

    sd a2, 8(sp)     # Preserve a2 (c) on stack (sp + 8)
    sd a3, 16(sp)    # Preserve a3 (d) on stack (sp + 16)

    call add2_s      # add2_c(a, b)

    sd a0, 24(sp)    # Preserve a0 (tmp0) on stack
    
    ld a0, 8(sp)     # Restore a2 into a0 from stack
    ld a1, 16(sp)    # Restore a3 into a1 from stack

    call add2_s      # add2_c(c, d)

    mv a1, a0        # a1 (tmp1) = a0
    ld a0, 24(sp)    # Restore tmp0 into a0 from stack

    call add2_s      # add2_c(tmp0, tmp1)

    ld ra, (sp)      # Restore ra from stack
    addi sp, sp, 32  # Deallocate stack
    ret

