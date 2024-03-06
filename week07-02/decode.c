#include <stdio.h>
#include <stdint.h>

int add2_s(int a0, int a1);

int main(int argc, char *argv[]) {
    int r;

    // Run the assembly function on the actual processor
    r = add2_s(3, 4);
    printf("add2_s(3, 4) = %d\n", r);

    uint32_t iw;   // instruction word
    uint32_t *pc;  // address to an instruction word

    // Get the address to the first instruction (32 bits)
    pc = (uint32_t *) add2_s;
    // Get the instruction word pointed to by pc
    iw = *pc;
    // Print the instruction word in hex
    printf("[pc = %p] iw = %X\n", pc, iw);

    // Assume the instruction in an r-type and get the
    // r-type fields
    uint32_t opcode;
    uint32_t funct3;
    uint32_t funct7;
    uint32_t rd;
    uint32_t rs1;
    uint32_t rs2;

    opcode = iw & 0b1111111;
    funct3 = (iw >> 12) & 0b111;
    funct7 = (iw >> 25) & 0b1111111;
    rd     = (iw >> 7)  & 0b11111;
    rs1    = (iw >> 15) & 0b11111;
    rs2    = (iw >> 20) & 0b11111;

    printf("opcode  = %d\n", opcode);
    printf("funct3  = %d\n", funct3);
    printf("funct7  = %d\n", funct7);
    printf("rd      = %d\n", rd);
    printf("rs1     = %d\n", rs1);
    printf("rs2     = %d\n", rs2);

    // Point pc to the next instruction in add2_s
    pc = pc + 1;
    iw = *pc;
    printf("[pc = %p] iw = %X\n", pc, iw);

    return 0;
}
