#include <stdio.h>
#include <math.h>
int gcd(int m, int n);
int main (void)
{
    int n,m;
    printf("Calculate the Geatest Common Divisor of two integers.\n");
    printf("Enter two integers:");
    scanf("%d %d" ,&m ,&n);
    printf("The Greatest Common Divisor is: %d" ,gcd(m,n));
}
int gcd(int m, int n)
{
    int remainder = 1;
    if (n==0)
    return m;
    else 
    {
       while (n>0)
       {
        remainder = m % n;
        m =  n;
        n = remainder;
       }
       return m;
    }

}