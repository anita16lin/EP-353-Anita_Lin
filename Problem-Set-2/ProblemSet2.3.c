#include <stdio.h>
#include <stdlib.h>

//Logic is A to C, B to A, then A to B
int main() {
    int a;
    int b;
    int c;
    a = 10;
    b = 20;
    printf("Original A = %d B = %d\n", a, b);
    c = a;
    a = b;
    b = c;
    printf("Swap A = %d B = %d\n", a, b);
    return 0;
}