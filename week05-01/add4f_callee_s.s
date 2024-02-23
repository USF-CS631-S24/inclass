.global add4f_callee_s

# Add two args
#
# a0 - int a
# a1 - int b
add2_s:
    add a0, a0, a1
    ret

# Add four args
#
# a0 - int a
# a1 - int b
# a2 - int c
# a3 - int d

# s0 - int tmp0

# We use a callee-saved register approach.
# This means that we preserve values accross
# function calls by using the s registers.
# However, since we are also a "callee", we
# need to preserve any s register we use at
# the beginning of the function and restore
# them before we return.

add4f_callee_s:
    addi sp, sp, -32 # Must be a multiple 16
    sd ra, (sp)      # Preserve ra on stack
    sd s0, 8(sp)     # Preserve s0, s1, s2 on stack
    sd s1, 16(sp)
    sd s2, 24(sp)

    # a0 and a1 already set

    mv s0, a2        # Preserve a2 in s0
    mv s1, a3        # Preserve a3 in s1

    call add2_s      # add2_c(a, b)

    mv s2, a0        # Preserve a0 (tmp0) in s2    

    mv a0, s0        # Restore a2 from s0
    mv a1, s1        # Restore a3 from s1

    call add2_s      # add2_c(c, d)

    mv a1, a0        # a1 (tmp1) = a0
    mv a0, s2        # Restore tmp0 into a0 from s2

    call add2_s      # add2_c(tmp0, tmp1)

    ld ra, (sp)      # Restore ra from stack
    ld s0, 8(sp)     # Restore s0, s1, s2 from stack
    ld s1, 16(sp)
    ld s2, 24(sp)
    addi sp, sp, 32  # Deallocate stack
    ret

    
