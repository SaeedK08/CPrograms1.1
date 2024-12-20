#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int printTabel();
void fillZeroArray(int v[], int n);
void frequencyArray(int v[],int n, int number);
int main (void)
{
    int number;
    printf("Hur manga ganger vill du kasta tarning?\n");
    scanf("%d" ,&number);
    srand(time(NULL));
    int a[7] = {0};
    frequencyArray(a,7,number);
}

void frequencyArray(int v[],int n,int number)
{
  
   for (int j=0;j<=number;j++)
        {
            int value = rand()%6+1;
            v[value]++;
        }
        for (int i=1;i<n;i++)
        {
            printf("%d " ,v[i]);
        }
        
}
void fillZeroArray(int v[], int n)
{
    for (int i=0;i<n;i++)
    {
        v[i] = 0;
    }
    return;
}

