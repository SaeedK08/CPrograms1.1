#include <stdbool.h> 
#include <stdio.h>
int main(void)
{
int digit_count[10] = {false};
 long long int number;
 long digit;
 int i;
 while (1)
 {
printf("Enter a number: \n");
scanf("%lld" ,&number);
if (number<=0)
break;
while(number>0)
     {
         digit = number % 10;
        digit_count[digit]++;
        number = number / 10;
    }
for (i=0;i<10;i++)
    {
        printf("%d " ,i);
    }
    printf("\n");
int occurrences;
for (i=0;i<10;i++)
{
    occurrences = digit_count[i];
    printf("%d " ,occurrences);
}
for(i=0;i<10;i++)
{
    digit_count[i] = 0;
}
printf("\n");
}
 return 0;
}