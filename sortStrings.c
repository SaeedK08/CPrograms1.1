#include <stdio.h>
#include <string.h>
#define MAX 100
#define WORDLENGTH 30
void sortWords(char wordList[][WORDLENGTH+1], int length);
void printWords(char wordList[][WORDLENGTH+1] ,int length);
int main (void)
{
    int nrOfWords = 5;
    char wordList[nrOfCards][WORDLENGTH +1];
    for (int i=0;i<nrOfWords;i++)
    {
        printf("Type a word: \n");
        scanf("%[^\n]%*c" ,wordList[i]);
    }
    sortWords(wordList, nrOfWords);
    printWords(wordList, nrOfWords);
    
}
void sortWords(char wordList[][WORDLENGTH+1], int length)
{
    for(int i=0;i<length-1;i++)
    {
        for(int j=0;j<length-1;j++)
        {
            int result = strcmp(wordList[j], wordList[j+1]);
            if(result>0)
            {
                for(int i=0;i<WORDLENGTH+1;i++)
                {
                    char tmp = wordList[j][i];
                    wordList[j][i] = wordList[j+1][i];
                    wordList[j+1][i] = tmp;
                }
            } 
        }
    }
}
void printWords(char wordList[][WORDLENGTH+1] ,int length)
{
    for(int i=0;i<length;i++)
    {
        printf("Wordnr %d: %s\n" , i+1,wordList[i]);
    }
}