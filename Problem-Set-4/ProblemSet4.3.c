#include <stdio.h>

int main()
{
    FILE *file;
    file = fopen("LoremIpsum.txt", "r");
    if(file == NULL){
        printf("File cannot be opened or does not exist");
        return 1;
    }
    
    int frequency[26];
    int ch;
    for(ch = 0; ch<26; ch++)
    {
        frequency[ch] = 0;
    }
    
    //char string[5];
   // while(fgets(string, 5, file) != NULL)
   while(1)
    {
        ch = fgetc(file);
        if(ch == EOF) break;

        if ('a' <= ch && ch <= 'z')
            frequency[ch- 'a']++;
        else if ('A' <= ch && ch <= 'Z')
            frequency[ch-'A']++;
    }
    for(int i = 0; i < 26;i++){
            printf("%d", frequency[i]);
            printf("\n");
    }
    return 0;
}

/*I found this resource online to print characters but I can't for the 
life of me figure out how to index multidimensional arrays. And I didn't want to 
go down the "dumb" way by printing every single possibility. So this is 
what I've got. Maybe we will learn more about it in class. 
*/