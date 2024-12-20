#include <stdio.h>
#include <string.h>
#define WORDLENGTH 20
int main(void)
{   
    char word[WORDLENGTH+1];
    char smallestWord[WORDLENGTH+1] = "z";
    char largestWord[WORDLENGTH+1] = "a";
    do
    {
        printf("Enter a word: ");
        scanf("%s%*c" ,word);
        if(strcmp(word,smallestWord)<0)
        strcpy(smallestWord,word);
        if(strcmp(word,largestWord)>0)
        strcpy(largestWord,word);
    }while ((strlen(word)) != 4);
    printf("Smallest word: %s\n" ,smallestWord);
    printf("Largest word: %s\n" ,largestWord);
}