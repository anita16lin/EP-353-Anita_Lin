#include <stdio.h>
#include <stdlib.h>

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
    printf("New A = %d B = %d\n", a, b);
    return 0;
}