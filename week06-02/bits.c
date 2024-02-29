#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

// A walk-through of bit manipulation in C and RISC-V assembly


// Print the binary of a value at address and of length bytes.
void prbin(char *prefix, const void* address, int length, bool space_every_4_bits) {
    unsigned char* byte_ptr = (unsigned char*)address;
    printf("%s 0b", prefix);

    for (int i = length-1; i >= 0; i--) {
        for (int j = 7; j >= 0; j--) {  // Loop for each bit
            printf("%d", (byte_ptr[i] >> j) & 1);
            if (space_every_4_bits && j % 4 == 0 && j != 0) {
                printf(" ");
            }
        }
        if (i > 0) {
            printf(space_every_4_bits ? " " : "");
        }
    }
    printf("\n");
}

// Helper to print value in hex to match prbin()
void prhex(char *prefix, uint32_t value) {
    printf("%s %X\n", prefix, value);
}

// Prototypes for assembly bit operations functions
// We need different type signatures so the C compiler
// generates the correct code to handle the return value.

uint8_t and_s(uint8_t a, uint8_t b);
uint32_t and_w(uint32_t a, uint32_t b);
uint8_t or_s(uint8_t a, uint8_t b);
uint32_t or_w(uint32_t a, uint32_t b);
uint8_t xor_s(uint8_t a, uint8_t b);
uint32_t xor_w(uint32_t a, uint32_t b);
uint8_t not_s(uint8_t a);
uint32_t not_w(uint32_t a);

uint32_t sll_w(uint32_t a, int b);
uint32_t srl_w(uint32_t a, int b);
uint32_t sra_w(uint32_t a, int b);


int main(int argc, char *argv[]) {
    uint8_t a, b, r;
    uint32_t aw, bw, rw;

    a = 0b11001010;
    b = 0b10011001;

    aw = 0xFFAA1122;
    bw = 0x50B3811E;

    // AND
    printf("--- AND ----\n");
    prbin("a          =", &a, 1, true);
    prbin("b          =", &b, 1, true);
    r = a & b;
    prbin("[c] a&b    =", &r, 1, true);
    r = and_s(a, b);
    prbin("[s] a&b    =", &r, 1, true);
    printf("\n");
    prhex("aw         =", aw);
    prhex("bw         =", bw);
    prbin("aw         =", &aw, 4, true);
    prbin("bw         =", &bw, 4, true);
    rw = aw & bw;
    prbin("[c] aw&bw  =", &rw, 4, true);
    rw = and_w(aw, bw);
    prbin("[s] aw&bw  =", &rw, 4, true);
    printf("\n");

    // OR
    printf("--- OR ----\n");
    prbin("a          =", &a, 1, true);
    prbin("b          =", &b, 1, true);
    r = a | b;
    prbin("[c] a|b    =", &r, 1, true);
    r = or_s(a, b);
    prbin("[s] a|b    =", &r, 1, true);
    printf("\n");
    prhex("aw         =", aw);
    prhex("bw         =", bw);
    prbin("aw         =", &aw, 4, true);
    prbin("bw         =", &bw, 4, true);
    rw = aw | bw;
    prbin("[c] aw|bw  =", &rw, 4, true);
    rw = or_w(aw, bw);
    prbin("[s] aw|bw  =", &rw, 4, true);
    printf("\n");

    // XOR
    printf("--- XOR ----\n");
    prbin("a          =", &a, 1, true);
    prbin("b          =", &b, 1, true);
    r = a ^ b;
    prbin("[c] a^b    =", &r, 1, true);
    r = xor_s(a, b);
    prbin("[s] a^b    =", &r, 1, true);
    printf("\n");
    prhex("aw         =", aw);
    prhex("bw         =", bw);
    prbin("aw         =", &aw, 4, true);
    prbin("bw         =", &bw, 4, true);
    rw = aw ^ bw;
    prbin("[c] aw^bw  =", &rw, 4, true);
    rw = xor_w(aw, bw);
    prbin("[s] aw^bw  =", &rw, 4, true);
    printf("\n");

    // NOT
    printf("--- NOT ----\n");
    prbin("a          =", &a, 1, true);
    r = ~a;
    prbin("[c] ~a     =", &r, 1, true);
    r = not_s(a);
    prbin("[s] ~a     =", &r, 1, true);
    printf("\n");
    prhex("aw         =", aw);
    prbin("aw         =", &aw, 4, true);
    rw = ~aw;
    prbin("[c] ~aw    =", &rw, 4, true);
    rw = not_w(aw);
    prbin("[s] ~bw    =", &rw, 4, true);
    printf("\n");

    // SHIFTS

    aw = 0b00010110;
    
    // SHIFT LEFT LOGICAL
    printf("--- SLL ----\n");
    prbin("aw         =", &aw, 4, true);
    printf("aw         = %u\n", aw);
    rw = aw << 1;
    prbin("aw<<1      =", &rw, 4, true);
    rw = sll_w(aw, 1);
    prbin("aw<<1      =", &rw, 4, true);
    printf("aw<<1      = %u\n", rw);
    rw = aw << 2;
    prbin("aw<<2      =", &rw, 4, true);
    rw = sll_w(aw, 2);
    prbin("aw<<2      =", &rw, 4, true);
    printf("aw<<2      = %u\n", rw);
    printf("\n");

    // SHIFT RIGHT LOGICAL
    printf("--- SRL ----\n");
    prbin("aw         =", &aw, 4, true);
    printf("aw         = %u\n", aw);
    rw = aw >> 1;
    prbin("aw>>1      =", &rw, 4, true);
    rw = srl_w(aw, 1);
    prbin("aw>>1      =", &rw, 4, true);
    printf("aw>>1      = %u\n", rw);
    rw = aw >> 2;
    prbin("aw>>2      =", &rw, 4, true);
    rw = srl_w(aw, 2);
    prbin("aw>>2      =", &rw, 4, true);
    printf("aw>>2      = %u\n", rw);
    printf("\n");

    // SHIFT RIGHT ARITMETIC
    printf("--- SRA ----\n");

    aw = -32;
    prbin("aw         =", &aw, 4, true);
    printf("aw         = %d\n", (int) aw);
    rw = aw >> 1;
    prbin("aw>>1 (l)  =", &rw, 4, true);
    rw = (int) aw >> 1;
    prbin("aw>>1 (a)  =", &rw, 4, true);
    printf("rw         = %d\n", (int) rw);
    printf("\n");

    // 2's complement
    printf("--- 2's complement ----\n");

    a = 0b00001000; // 8
    prbin("a          =", &a, 1, false);
    r = ~a; 
    prbin("~a         =", &r, 1, false);
    r = r + 1;
    prbin("(~a)+1     =", &r, 1, false);
    printf("(~a)+1=    = %d\n", (int8_t) r);
    printf("\n");

    // Masking
    a = 0b10111100;
    prbin("a                 =", &a, 1, false);
    r = (a >> 2);
    prbin("a>>2              =", &r, 1, false);
    r = r & 0b00001111;
    prbin("(a>>2)&0b00001111 =", &r, 1, false);
    printf("\n");

    a = 0b10100100;
    prbin("a                 =", &a, 1, false);
    r = (a >> 2);
    prbin("a>>2              =", &r, 1, false);
    r = r & 0b00001111;
    prbin("(a>>2)&0b00001111 =", &r, 1, false);
    printf("\n");

    // get_bitseq
    printf("--- get_bitseq ----\n");
    uint32_t x = 0b01000101000;
    prbin("x          =", &x, 4, false);

    int start = 3;
    int end = 5;
    int len = ((end - start) + 1);

    uint32_t v = x >> start;
    prbin("v          =", &v, 4, false);

    uint32_t m = 0b1 << len;
    prbin("m          =", &m, 4, false);
    m = m - 1;
    prbin("m          =", &m, 4, false);

    v = v & m;    
    prbin("v          =", &v, 4, false);
    printf("\n");

    // SHIFT RIGHT ARITHMETIC
    int8_t n = 0b11110000;

    printf("--- SRA ----\n");

    printf("n          = %d\n", n);
    prbin("n          =", &n, 1, false);
    r = n >> 2;
    prbin("[c] n>>2   =", &r, 1, false);
    printf("[c] n>>2   = %d\n", (int8_t) r);
    r = sra_w(n, 2);
    prbin("[s] n>>2   =", &r, 1, false);
    printf("[s] n>>2   = %d\n", (int8_t) r);

    return 0;
}

