#include <stdio.h>
#include <string.h>
#define MAX 20
#define WORDLENGTH 20
void addWordPairs(char s1[][WORDLENGTH+1], char s2[][WORDLENGTH+1], int *pNrOfPairs);
void printWordPairs(char s1[][WORDLENGTH+1] ,char s2[][WORDLENGTH+1] ,int *pNrOfPairs);
void deletePairs(char s1[][WORDLENGTH+1], char s2[][WORDLENGTH+1], char s3[][WORDLENGTH+1]);
int main(void)
{
    int nrOfPairs = 0, choice;
    char swedishList[nrOfCards][WORDLENGTH+1];
    char englishList[nrOfCards][WORDLENGTH+1];
    char delete[nrOfCards][WORDLENGTH+1];
    do
    {
        printf("(1) Skriva in  (2) Skriva ut  (3) Radera  (4) Avsluta: ");
        scanf("%d" ,&choice);
        switch(choice)
        {
        case 1:
            addWordPairs(swedishList, englishList, &nrOfPairs);
            break;
        case 2:
            printWordPairs(swedishList, englishList, &nrOfPairs);
            break;
        case 3:
            deletePairs(swedishList, englishList, delete);
            nrOfPairs = 0;
        }
    }while(choice != 4);
    printf("Avslutar\n");
}
void addWordPairs(char s1[][WORDLENGTH+1], char s2[][WORDLENGTH+1], int *pNrOfPairs)
{
    for(int i=*pNrOfPairs;i<nrOfCards;i++)
    {
        printf("svenska: ");
        scanf("%s" ,s1[i]);
        if (strlen(s1[i]) == 1)
        break;
        printf("Engelska: ");
        scanf("%s" ,s2[i]);
        (*pNrOfPairs)++;
    }
    
}
void printWordPairs(char s1[][WORDLENGTH+1] ,char s2[][WORDLENGTH+1] ,int *pNrOfPairs)
{
    if ((*pNrOfPairs) == 0)
    {
        printf("Gloslistan ar tom\n");
    }
    else
    {
        for (int i=0;i<*pNrOfPairs;i++)
        {
            printf("%s - %s\n" ,s1[i] ,s2[i]);
        }
    }
    
}
void deletePairs(char s1[][WORDLENGTH+1], char s2[][WORDLENGTH+1], char s3[][WORDLENGTH+1])
{
    for (int i=0;i<nrOfCards;i++)
    {
        strcpy(s1[i], s3[i]);
        strcpy(s2[i], s3[i]);
    }

}