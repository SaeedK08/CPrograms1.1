#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define LENGTH 4
typedef struct letters
{
    char letter;
    int taken;
} Letter;
void generateCode(Letter codeLetters[], char code[]);
int checkLetters(char guess[]);
void matchedLetters(char code[], char guess[], int *pRigtPlace, int *pWrongPlace);
int main(void)
{
    srand(time(NULL));
    Letter codeLetters[] = {{'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0}, {'f', 0}, {'g', 0}};
    char code[LENGTH+1];
    generateCode(codeLetters, code);
    //printf("%s\n" ,code);
    char guessCode[LENGTH+1];
    int rightLetterWrongPlace = 0, rightLetterRightPlace = 0;
    do
    {
        while(1)
        {
        printf("Gissa en kod (fyra bokstaver a-g) :");
        scanf("%s" ,guessCode);
        if(strlen(guessCode) != 4 || checkLetters(guessCode)==1)
            printf("Fel inmatning\n");
        else 
            break;
        }
        if(strcmp(guessCode,code)==0)
            break;
        matchedLetters(code, guessCode, &rightLetterRightPlace, &rightLetterWrongPlace);
        printf("%d Korrekta, " ,rightLetterRightPlace);
        printf("%d ratt bokstaver pa fel plats\n" ,rightLetterWrongPlace);

    } while (strcmp(guessCode,code)!=0);
    printf("Korrekt kod\n");
}
void generateCode(Letter codeLetter[], char code[])
{
    for (int i = 0; i < LENGTH; i++)
    {
        int j;
        do
        {
            j = rand() % 7;
        } while (codeLetter[j].taken != 0);
        code[i] = codeLetter[j].letter;
        codeLetter[j].taken = 1;
    }
}
int checkLetters(char guess[])
{
    int n = strlen(guess);
    for(int i=0;i<n;i++)
    {
        if (guess[i]>'g')
            return 1;
    }
}
void matchedLetters(char code[], char guess[], int *pRightPlace, int *pWrongPlace)
{
    *pRightPlace = 0;
    *pWrongPlace = 0;
    for(int i=0;i<LENGTH;i++)
    {
        for(int j=0;j<LENGTH;j++)
        {
            if(code[i]==guess[j]&&i==j)
                (*pRightPlace)++;
            else if(code[i]==guess[j]&&i!=j)
                (*pWrongPlace)++;
        }
    }
}
