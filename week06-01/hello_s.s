# Hello World in RISC-V Assembly

# In Assembly, we can have both code (.text) sections and
# data (.data) sections. By default, we just have code sections.
# If we want to define data, we need to use the .data directive.

.data

# Data has labels just like code.
hello_string:
    .string "Hello, World! argc = %d argv[0] = %s argv[1] = %s\n"

# Because we just defined a .data section, now we need to tell
# the assembly we have a code section with the .text directive.
.text

.global main        # We need to make main global so it can be linked.
.global printf      # We need to tell the assembly that printf will
                    # come from somewhere else.

main:
    addi sp, sp, -16
    sd ra, (sp)

    # la is a special pseudo instruction that loads the address
    # of the label into a0.

    ld a2, (a1)
    addi a1, a1, 8
    ld a3, (a1)
    mv a1, a0
    la a0, hello_string

    call printf

    ld ra, (sp)
    addi sp, sp, 16
    ret
