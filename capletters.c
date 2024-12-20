#include <stdio.h>
int main(void)
{
    char ch, tmp;
     ch='a';
   while (ch != 'P')
    {
        printf("Ange bokstav:");
        scanf(" %c" ,&ch);
        scanf("%c" ,&tmp);
        if (ch>='a' && ch<='z')
        {
        ch = ch - 'a' + 'A';
        printf("%c\n" ,ch);
        }
        
    }
}

