#include <stdio.h>

int main()
{
    FILE *file;
    file = fopen("LoremIpsum.txt", "r");
    if(file == NULL){
        printf("File cannot be opened or does not exist");
        return 1;
    }
    //Declare array
    int frequency[90][88];
    
    //for the ASCII index
    //Initialize first index to 89 values between 32 and 122
    for(int i = 0; i < 90; i++)
    {
        frequency[i] = i + 32;
    }

    //for the count
    //initialize second index to all zeroes
    for(int i = 0; i < 89; i++)
    {
        frequency[i][0]= 0;
    }

    //declare string t0 1000
    char string[1000];

    //if the character matches the first index, add 1 to the second index
    while(fgets(string, 1000, file) != NULL)
    {
        for(int j = 0; j < 89; j++)
        {
            for(int i = 32; i <= 122; i++)
        {
            if  (frequency[j] == i)
            {
                frequency[j][0]++; //add zeros? or variable with count
            }
        }
        }
    }
    
    for(int i = 0; i < 89;i++)
    {
            printf("ASCII: %d is represented %d times\n", frequency[i], frequency[i][0]);
    }

    //if(file) fclose(file);
    return 0;
}

/*I found this resource online to print characters but I can't for the 
life of me figure out how to index multidimensional arrays. And I didn't want to 
go down the "dumb" way by printing every single possibility. So this is 
what I've got. Maybe we will learn more about it in class. 
*/