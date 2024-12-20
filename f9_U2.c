#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
void fillArray(int v[], int n);
void printArray(int v[], int n);
void shuffleArray(int v[] ,int n);
int main (void)
{
    int val;
    srand(time(NULL));
    printf("Vilket ar det hogsta heltal du vill ha med (1-1000)?\n");
    scanf("%d" ,&val);
    while (val<1||val>1000)
    {
        printf("Du maste valja mellan 1 och 1000\n");
        scanf("%d" ,&val);
    }
    int a[val];
    fillArray(a,val);
    shuffleArray(a,val);
    printArray(a,val);
}
    void fillArray(int v[] ,int n)
{
    for(int i=0;i<n;i++)
    {
        v[i] = i+1;
    }
}
    void shuffleArray(int v[] ,int n)
    {
        for(int i=0;i<n;i++)
        {
            int j = rand()%(n-1)+1;
            int tmp = v[j];
            v[j] = v[i];
            v[i] = tmp;
        }
        return;
    }
    void printArray(int v[], int n)
    {
        for(int i=0;i<n;i++)
        {
            printf("%d, " ,v[i]);
        }
    }
