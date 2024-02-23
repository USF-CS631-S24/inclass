#include <stdio.h>
#include <stdlib.h>

int sumarr_idx_c(int arr[], int len);
int sumarr_ptr_c(int arr[], int len);
int sumarr_idx_s(int arr[], int len);
int sumarr_ptr_s(int arr[], int len);


int main(int argc, char **argv) {
    int arr[1024] = {0};
    int len = 0;
    int c_result;
    int s_result;

    for (len = 0; len < argc - 1; len++) {
        arr[len] = atoi(argv[len + 1]);
    }

    c_result = sumarr_idx_c(arr, len);
    printf("C: %d\n", c_result);

    s_result = sumarr_ptr_c(arr, len);
    printf("Asm: %d\n", s_result);

    c_result = sumarr_idx_s(arr, len);
    printf("C: %d\n", c_result);

    s_result = sumarr_ptr_s(arr, len);
    printf("Asm: %d\n", s_result);

    return 0;
}
