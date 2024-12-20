#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define CHARACTERS 35
void fillRandomCharacters(char randomCharacters[]);
void generateCode(char code[], int nrOfDigits, char randomCharacters[]);
void guessCode(char code[], int nrOfDigits, char randomCharacters[]);
void printCode(char code[], char givenCode[], int nrOfDigits);
int checkCode(char code[], char givenCode[], int nrOfDigits);
int main(void)
{
    srand(time(NULL));
    int nrOfDigits = 2;
    char randomCharacters[CHARACTERS+1];
    fillRandomCharacters(randomCharacters);
    char code[nrOfDigits];
    generateCode(code, nrOfDigits,randomCharacters);
    guessCode(code,nrOfDigits,randomCharacters);
}
void fillRandomCharacters(char randomCharacters[])
{
    for(int i=0;i<CHARACTERS;i++)
    {
        if(i<=25)
            randomCharacters[i] = 'A'+i;
        else
            randomCharacters[i] = '1'+i-26;
    }
}
void generateCode(char code[], int nrOfdigits, char randomCharacters[])
{
    for(int i=0;i<nrOfdigits;i++)
    {
        code[i] = randomCharacters[rand()%CHARACTERS];
    }
    printf("%s" ,code);
}
void printCode(char code[], char givenCode[], int nrOfDigits)
{
    for(int i=0;i<nrOfDigits;i++)
    {
        if(code[i]==givenCode[i])
        {
            printf("%c", code[i]);
        }
        else
        {
            printf("*");
        }
    }
    printf(": ");
}
int checkCode(char code[], char givenCode[], int nrOfDigits)
{
    for(int i=0;i<nrOfDigits;i++)
    {
        if(code[i]!=givenCode[i])
            return 0;
    } 
    return 1;
}
void guessCode(char code[], int nrOfDigits,char randomCharacters[])
{
    char givenCode[nrOfDigits+1];
    printf("Gissa koden \n");
    while(nrOfDigits<=5)
    {
        printf("nrOfDigits %d\n" ,nrOfDigits);
        printCode(code,givenCode,nrOfDigits);
        scanf("%s" ,givenCode);
        if(checkCode(code,givenCode,nrOfDigits)==1)
        {
            printf("%s Korrekt\n" ,givenCode);
            nrOfDigits++;
            generateCode(code,nrOfDigits,randomCharacters);
        }
    }
    printf("Game Over\n");
}
/*for(int i=0;i<nrOfDigits;i++){               //generate random string of letters A-Z and numbers 1-9
        int r = rand()%(9+'Z'-'A'+1);
        if(r<9){
            code[i] = '1' + r;
        }else{
            code[i] = 'A' + (r-9);
        }
    }*/