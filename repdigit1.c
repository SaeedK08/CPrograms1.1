#include <stdbool.h> 
#include <stdio.h>
int main(void)
{
int digit_count[10] = {false};
 long long int number;
 long digit;
printf("Enter a number: \n");
scanf("%lld" ,&number);
while(number>0)
{
    digit = number % 10;
    digit_count[digit]++;
    number = number / 10;
}
int repeated = 0;
for ( int i=0;i<10;i++)
{
    if (digit_count[i]>1)
    {
        printf("%d " ,i);
        repeated = 1;
    }
}
if (!repeated)
{
    printf("No repeated digits\n");
}
 return 0;
}