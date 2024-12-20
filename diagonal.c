#include <stdio.h>
int main(void)
{
    int storlek, i, j;
    printf("Ange storlek: \n");
    scanf("%d" ,&storlek);
    for (i=0;i<storlek;i++)
    {
        for (j=0;j<storlek;j++)
        {
            if (j == i || i + j == storlek - 1)
            {
                printf("*");
            }
            else 
            {
                printf("+");
            }

        }
        printf("\n");
    }

}