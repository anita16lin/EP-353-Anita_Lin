#include <stdio.h>

int LengthStr(char*);

int main(int argc, char const *argv[])
{
    char user;
    printf("Type in a string: ");
    scanf("%s", &user);
    printf("%s", &user);
    LengthStr(&user);
}

int LengthStr(char* x)
{
    char *blah = x;
    int i;

    for(i = 0; *x != '\0'; i++){
        *blah = x[i];
    }
    printf("Your string is %d values long", i-1);
    return 0;
}
