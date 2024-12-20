#include <stdio.h>
#include <string.h>
typedef struct complex
{
    float x;
    float y;
}Comp;
Comp createComplex(Comp c, int a, int b);
void printComplex(Comp c, int y);
void multiplyComplex(Comp *pComplex, float num);
int equals (Comp c1, Comp c2);
int main(void)
{
    Comp c1, c2;
    float number1 = -2.5, number2 = -1;
    c1 = createComplex(c1, 3, 2);
    c2 = createComplex(c2, 2, -3);
    printComplex(c1, c1.y);
    printComplex(c2, c2.y);
    multiplyComplex(&c1, number1);
    multiplyComplex(&c2, number2);
    printComplex(c1, c1.y);
    printComplex(c2, c2.y);
    int answer = equals(c1, c2);
    printf("%d" ,answer);
}
Comp createComplex(Comp c, int a, int b)
{
    c.x = a;
    c.y = b;
    return c;
}
void printComplex(Comp c, int y)
{
    if (y<0)
    {
        c.y = -1 * y;
        printf("%0.4f - %0.4fi\n" ,c.x, c.y);
    } 
    else
    printf("%0.4f + %0.4fi\n" ,c.x, c.y);
}
void multiplyComplex(Comp *pComp, float num)
{
    pComp->x = pComp->x * (num);
    pComp->y = pComp->y * (num);
}
int equals(Comp c1, Comp c2)
{
    if(c1.x==c2.x && c1.y==c2.y)
    return 1;
    else 
    return 0;
}