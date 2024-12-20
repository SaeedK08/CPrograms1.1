#include <stdio.h>
#include <math.h>
int numOfDigits(int n);
int main (void)
{
    int number;
    printf("Enter a number to check how many digits it has:\n");
    scanf("%d" ,&number);
    printf("Nubmer of digits: %d\n" ,numOfDigits(number));

}
int numOfDigits(int n)
{
    int digits;
    while(n>0)
    {
        n = n / 10;
        digits++;
    }
    return digits;
}