#include <stdio.h>
#include <string.h>

//Declare Function
char removeLastChar(char*);

//Test the function
int main()
{
    int max;
    max = 100;
    char a[max];
    printf("Enter max 100 characters\n");
    fgets(a, max,stdin);
    removeLastChar(a);
    return 0;
}

//Write Contents of the function
char removeLastChar(char *a)
{
    int length = strlen(a) - 2;
    a[length] = '\0';
    printf("New String is: %s\n", a);
    return *a;
}

//remember to input and output the same variable type char *