#include <stdint.h>

// Return the bits from start to end from num
uint32_t get_bitseq_c(uint32_t num, int start, int end) {
    uint32_t val;
    int len;
    uint32_t mask;

    // Determine the length of the range
    // If start is 10 and end is 12, 12 - 10 = 2,
    // but the len is really 3, so we need to add 1.
    len = (end - start) + 1;
    // Shift the range of bit we want to the beginning.
    val = num >> start;

    if (len == 32) {
        // Special case, if we want all bits
        mask = 0xFFFFFFFF;
    } else {
        // Compute the mask
        mask = (0b1 << len) - 1;
    }
    
    // Apply the mask
    val = val & mask;

    return val;
}
