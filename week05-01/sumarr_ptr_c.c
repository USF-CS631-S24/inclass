/* Sum an array of ints using pointer arithmetic */

/* In c, when a parameter is an array type, the value
 * of that is passed to the funtion is the address
 * of the first element of the array. So you can use
 * the array name as a pointer.
 */
int sumarr_ptr_c(int arr[], int len) {
    int sum = 0;
    int i;
    
    for (i = 0; i < len; i++) {
        sum = sum + *arr;
       /* In C, pointer arithmetic will multiply integers by
        * the size of data type of the pointer. In this example,
        * a is a pointer to an int, so the C compiler will
        * multiply 1 * 4 = 4 (bytes) in the generated code.
        */
        arr = arr + 1;
    }

    return sum;
}
