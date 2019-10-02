#include <stdio.h>
//Declare the function
int findPrimeNumber(int);

//Define the function so we can call it
int findPrimeNumber(int n){
    int j, flag = 1;

    for(j=2; j<= n/2; j++){
        if (n%j == 0){
            flag = 0;
            break;
        }
    }
    return flag;
}
//Run it through main
int main(){
    int i, flag;

    for(i=2; i<1000; i++){
        flag = findPrimeNumber(i);
        if(flag == 1)
            printf("%d\n", i);
    }
    return 0;
}

//modulo =0 means that it's not a prime number
//flag =0 declares that it's not a prime number
//https://www.programiz.com/c-programming/examples/prime-interval-function