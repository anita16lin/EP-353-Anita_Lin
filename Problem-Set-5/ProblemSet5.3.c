#include <stdio.h>
#include <stdlib.h> 

int main()
{
    FILE *file;
    
    //open file
    file = fopen("num.csv", "r");
    
    //check to see if file exists
    if (file == NULL)
    {
        printf("File cannot be opened or does not exist.\n");
        return 1;
    }
    //rewind(file);
    if ( fseek(file, 0L, SEEK_SET) != 0 ) { 
     /* Handle repositioning error */
    } 
    char string[50];
    int commacount = 0;
    while(fgets(string, 50, file) != NULL)
        if (string = ','){
            commacount ++;
        }
    

    printf("Number of commas: %d\n", commacount);

    //close open file
    if(file) fclose(file);
    
    return 0;
}