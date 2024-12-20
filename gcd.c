#include <stdio.h>
int main(void)
{
    int m,n=1,remainder;
    printf("Enter two integers: \n");
    scanf("%d %d" ,&m ,&n);
    
    if (m == 0)
    {
        remainder = n;
        printf("Greatest common divisor is %d" ,remainder);
    }
    if (n==0)
    {
        remainder = m;
        printf("Greatest common dividor is %d" ,remainder);
    }
    while (n != 0)
    {
        remainder = m % n;
         m = n;
         n = remainder;
    } 
     printf("Greatest common dividor is %d \n" ,m);
    
}