# AND
.global and_s
.global and_w
and_s:
and_w:
    and a0, a0, a1
    ret

# OR
.global or_s
.global or_w
or_s:
or_w:
    or a0, a0, a1
    ret

# XOR
.global xor_s
.global xor_w
xor_s:
xor_w:
    xor a0, a0, a1
    ret

# NOT 
# There is not "not" or "invert" in RISC-V, so use xor
.global not_s
.global not_w
not_s:
not_w:
    li t0, -1
    xor a0, a0, t0
    ret

# SLLW
.global sll_w
sll_w:
    sllw a0, a0, a1
    ret
 
# SRLW
.global srl_w
srl_w:
    srlw a0, a0, a1
    ret    

# SRAW
.global sra_w
sra_w:
    sraw a0, a0, a1
    ret
