#include <stdio.h>

int main() {
    char note;
    note = 'C';
    int a;
    a = (int)note;
    int b;
    switch (a) {
        case 65:
        case 66:
            b = a - 59;
            printf("Note: %c is Integer Value: %d\n", note, b);
        break;
        case 67: 
        case 68:
        case 69:
        case 70:
        case 71:
            b = a - 67;
            printf("Note: %c is Integer Value: %d\n", note, b);
        break;
    }
return 0;
}