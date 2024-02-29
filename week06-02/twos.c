#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    // int8_t is an 8 bit signed value.
    // -1 is represented as a 2s complement number
    int8_t sx = -1;
    // We can put the 8 bits in sx into the unsigned int ux
    uint8_t ux = sx;

    // This lets us see sx as an unsigned hex value
    printf("sx = %d, %x\n", sx, ux);

    return 0;    
}
