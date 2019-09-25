#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

int main(int argc, char const *argv[]) {
    char c = 'A';
    int a;
    a = (int)c;
    bool result_l, result_u;
    result_l = a >= 97 && a <= 122;
    result_u = a >= 65 && a <= 90;
    printf("A letter is lowercase: %d\n A letter is uppercase: %d\n", result_l, result_u);
    return 0;
}