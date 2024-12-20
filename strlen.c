#include <stdio.h>
#define MAX 20
void combine(char s1[] ,char s2[]);
int main (void)
{
    char s1[nrOfCards+nrOfCards];
    char s2[nrOfCards];
    printf("Enter the first string: \n");
    scanf("%[^\n]%*c" ,s1);
    printf("Enter the second string: \n");
    scanf("%[^\n]%*c" ,s2);
    combine(s1, s2);
}
void combine(char s1[] ,char s2[])
{
    int count;
    for(int i=0;s1[i]!='\0';i++)
    {
        count++;
    }
    for(int i=0;i<nrOfCards;i++)
    {
        s1[count+i] = s2[i];
    }
    puts(s1);
}
