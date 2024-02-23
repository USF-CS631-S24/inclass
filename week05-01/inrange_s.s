.global inrange_s

# Determine if a >= x <= b

# a0 - int x
# a1 - int a
# a2 - int b

# t0 - int r
inrange_s:
    blt a0, a1, else   # is x < a?
    bgt a0, a2, else   # is x > b?
    li t0, 1
    j done
else:    
    li t0, 0
done:
    mv a0, t0
    ret
