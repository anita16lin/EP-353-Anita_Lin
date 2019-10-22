#include <stdio.h>

int main(){
    int num[6] = {1, 2, 3, 4, 5, 6};
    int c;
    c = *(num + 0);
    for (int i = 1; i < 6; i ++){
        *(num + i - 1) = *(num + i);
    }
    *(num + 6 - 1) = c;
    printf("%d", num[0]);
}