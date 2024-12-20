#include <stdio.h>
int main (void)
{
    printf("Valkommen till tandsticksspelet.\n");
    printf("|||||||||||||||\n");
    int i,j,val1,val2,tandstickor=15;
    while(tandstickor>0)
    {
       do 
        {
        printf("Hur manga stickor vill du ta(1-3)?");
        scanf("%d" ,&val1);
        } while(val1<1 || val1>3 || val1>tandstickor);
        tandstickor -= val1;
        if (tandstickor==0)
        {
            printf("du vann\n");
            break;
        }
        for (i=0;i<tandstickor;i++)
        {
            printf("|");
        }
        printf("\n");

            if (tandstickor<=3)
            {
                val2=tandstickor;
            }
            else if (tandstickor<=9)
            {
                val2=2;
            }
            else 
            {
                val2=1;
            }
            printf("Datorn tar %d stickor\n" ,val2);
            tandstickor-=val2;
            if (tandstickor == 0)
            {
                printf("Datorn vann\n");
            }
            for (j=0;j<tandstickor;j++)
            {
                printf("|");
            }
            printf("\n");
    }

}
