#include <stdio.h>
#include <math.h>
float equation(float x);
int main (void)
{
    float x;
    printf("Enter a value for x:\n");
    scanf("%f" ,&x);
    printf("The value of x in the polynomial is: %.2f\n" ,equation(x));
}

float equation(float x)
{
    float powResult = pow(x,5) * 3 + pow(x,4) * 2 - pow(x,3) * 5 - pow(x,2);
    float functionResult = powResult + 7*x - 6;
    return functionResult;
}