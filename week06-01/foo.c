#include <stdio.h>

int foo(int x, int y) {
    return (x * 4) + y;
}

int main(int argc, char *argv[]) {
    int x = 3;
    int y = 4;

    x = foo(x, y);

    return x;
}
