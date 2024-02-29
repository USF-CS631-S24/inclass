#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    // An int is 32 bits
    // Each hex digit is 4 bits (because 2^4 = 16)
    // We have 8 hex digits, 8 * 4 = 32
    // It all checks out.
    int x = 0xFFAA1122;
    uint8_t v;

    // This C type casting allows us to get a pointer to x,
    // then tell the C compiler to treat the pointer as a
    // pointer to a uint8_t type (uint8_t *). Then we
    // derefrence the final pointer, but in doing so, the compiler
    // generates code (using the lb instruction) to get just one
    // byte from memory.
    v = *((uint8_t *) &x);

    printf("v = %X\n", v);

    return 0;
}
