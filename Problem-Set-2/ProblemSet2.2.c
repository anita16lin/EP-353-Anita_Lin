//include <math.h> to use pow for exponentials
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//I had to compute the functions individually because there were problems with heirarchy.
int main() {
    float f;
    int m;
    float c;
    float d;
    m = 60;
    c = (m-69);
    d = c/12;
    f = pow(2, d) * 440;
    printf("Midi Value: %d\nFrequency Value: %f Hz\n", m, f);
    return 0;
}