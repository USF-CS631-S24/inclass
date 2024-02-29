# Hello World in RISC-V Assembly

# In Assembly, we can have both code (.text) sections and
# data (.data) sections. By default, we just have code sections.
# If we want to define data, we need to use the .data directive.

.data

# Data has labels just like code.
hello_string:
    .string "Hello, World! %s argc = %d argv[1] = %s\n"

foo_string:
    .string "FOO"

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

    addi t0, a1, 8
    ld a3, (t0)
    mv a2, a0
    la a1, foo_string
    la a0, hello_string

    call printf

    ld ra, (sp)
    addi sp, sp, 16
    ret
