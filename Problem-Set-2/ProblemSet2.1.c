//need to include stdbool in order to use the boolean equation
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

/*first convert the character to an integer as per ASCII, 
then initialize variables with bool, 
then use comparisons to determine the TRUE case for lower case and upper case
lower case = 97 to 122
upper case = 65 to 90 */
int main(int argc, char const *argv[]) {
    char c = 'A';
    int a;
    a = (int)c;
    bool result_l, result_u;
    result_l = a >= 97 && a <= 122;
    result_u = a >= 65 && a <= 90;
    printf("A letter is lowercase: %d\nA letter is uppercase: %d\n", result_l, result_u);
    return 0;
}