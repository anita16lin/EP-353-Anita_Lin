#include <stdio.h>

int main(){
    int s = 6;
    int rotation = -1;
    int num[6] = {1, 2, 3, 4, 5, 6};
    
    int c;
    if(rotation > 0){
        for (int j = 0; j < rotation; j++){
            c = *(num + 0);
            for (int i = 1; i < 6; i ++){
                *(num + i - 1) = *(num + i);
            }
            *(num + s - 1) = c;
        }
    }
    else {
        int rotate;
        rotate = rotation * -1;
        for (int j = 0; j < rotate; j++){
            c = *(num + s - 1);
            for (int i = 0; i < s; i ++){
                *(num + s - i) = *(num + s - i - 1);
            }
            *(num + 0) = c;
        }    
    }
    //print the rotated array
    for (int i = 0; i < 6; i ++){
        printf("%d\n", num[i]);
    }
}