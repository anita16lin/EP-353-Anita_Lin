/* This file is a simple C program to display "Hello, World!" 
on the screen and say "Hello, World" through speaker. 
Since, it's a very simple program, 
it is often used to illustrate the syntax of a programming language.

To compile and run this program type:
gcc HelloWorld.c -o HelloWorld && ./HelloWorld
 */


//A preprocessor commands that tells compiler to 
//include the contents of stdio.h and stdlib.h file.
#include <stdio.h>
#include <stdlib.h>

//A function named "main." Every C program begins with the main() function.
//"main"is where the program starts when executed.
int main(int argc, char const *argv[]) {
  printf("Hello, World"); //Print Hello World to the terminal window
  system("say Hello, World"); //Convert text to audible speech
  return 0; //Exit status of 0 to signify that the program reached the end
}
