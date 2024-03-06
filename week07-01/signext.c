#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[]) {
    uint64_t immu = 0b111111111101;
    uint32_t start = 11;
    uint32_t distance = 64 - start;
    int64_t imm;

    imm = immu << distance;
    imm = imm >> distance;

    printf("imm = %ld\n", imm);

    return 0;
}
