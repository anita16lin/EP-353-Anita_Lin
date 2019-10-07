#include <stdio.h>
//Initialize the function that contains the array
void printArray(int x, int *arr);
//Run the function + declare the array we are using
int main(int argc, char const *argv[]){
    //initialize + declare array
    int num[5] = {2, 4, 6, 8, 10};
    
    //initialize scanf
    int x;
    printf("Type in an integer value: ");
    scanf("%d", &x);
    printf("You typed in %d.\n", x);
    printArray(x, num);
    return 0;
}
//Declare the function and the boolean to determine if the numbers are matching
void printArray(int x, int *arr){
    int flag;
    flag = 0;
    for(int i = 0; i < 5; i++){
        if(arr[i] == x)
        {
            flag = 1;
            printf("True! Your input value %d is in the array index %d.\n", x, i);
            break;
        }
    }
    if(flag == 0)
    {
        printf("False! Your input value %d is not in the array.\n", x);
    }
}