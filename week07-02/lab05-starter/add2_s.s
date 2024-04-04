.global add2_s

add2_s:
#    add a0, a0, a1
#    addi a0, a0, 5
    j foo   
back:

    ret

foo:
    j back
