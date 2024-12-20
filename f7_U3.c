#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LENGTH 8
void printArray(int v[],int n);
void randomArray(int v[],int n);
void sequenceArray(int v[],int n);
int main (void)
{
int a[LENGTH];
randomArray(a,LENGTH);
printArray(a,LENGTH);
sequenceArray(a,LENGTH);
printArray(a,LENGTH);
return 0;
}

void printArray(int v[],int n)
{
    for (int i=0;i<n;i++)
    {
        printf("%3d " ,v[i]);
    }
    printf("\n");
}

void randomArray(int v[],int n)
{
    srand(time(NULL));
    for (int i=0;i<n;i++)
    {
        v[i] = rand()%21-10;
    } 
}

void sequenceArray(int v[], int n)
{   
    for (int i=0;i<n-1;i++)
    {
      for (int j=0;j<n-i-1;j++)
      if (v[j]>v[j+1])
      {
        int tmp = v[j];
        v[j] = v[j+1];
        v[j+1] = tmp;
      }
    }
}