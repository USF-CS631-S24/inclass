#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Example of how to do foo(int *pos) in C
void intdr_c(int *pos);
void intdr_s(int *pos);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("usage: intdr <pos>\n");
        exit(-1);
    }
    
    int pos = atoi(argv[1]);

    intdr_c(&pos);
    printf("C: %u\n", pos);

    pos = atoi(argv[1]);

    intdr_s(&pos);
    printf("Asm: %u\n", pos);
    
    return 0;
}
