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
    if (fseek(file, 0L, SEEK_SET) != 0 ) { 
     /* Handle repositioning error */
    } 
    
    //counts how many commas there are
    int c;
    int commacount = 1;
    while((c = fgetc(file)) != EOF) 
        if (c == ','){
            commacount ++;
        }
    printf("Number of commas: %d\n", commacount);

    //making a dynamic array with malloc
    int *array = malloc(commacount * sizeof(int));

    //checking to see if malloc worked
    if (array == NULL){
        fprintf(stderr, "malloc failed\n");
        return -1;
    }
    
    //rewind(file);
    if (fseek(file, 0L, SEEK_SET) != 0 ) { 
     /* Handle repositioning error */
    }     
    
   /* I couldn't figure this part out. LOL but I counted the commas. 
    while((c = fgetc(file)) != EOF)
        for(int i = 0; i < 99; i++) {
            if(c != "," && c -1 ==','){
                int
            }
        }
    */

    //Free the array from HEAP
    free(array);
    
    //close open file
    if(file) fclose(file);
    
    return 0;
}