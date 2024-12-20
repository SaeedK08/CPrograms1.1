#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LENGTH 31
void array(int v[], int n);
float medelvarde(int v[], int n);
float median(int v[] ,int n);
int typvarde(int v[] ,int n);
int main (void)
{
    srand(time(NULL));
    int aldrar[LENGTH] = {0};
    int antal;
    printf("Hur manga personer vill du gora statistik pa?\n");
    scanf("%d" ,&antal);
    if (antal<31)
    {
        array(aldrar, antal);
        medelvarde(aldrar, antal);
        median(aldrar, antal);
        typvarde(aldrar, antal);
    }
}
void array(int v[] ,int n)
{
    for(int i=0;i<n;i++)
    {
        v[i] = rand()%21+20;
        printf("%d, " ,v[i]);
    }
    printf("\n");
}
float medelvarde(int v[] ,int n)
{
    int sum = 0;
    for (int i=0;i<n;i++)
    {
        sum += v[i];
    }
    float medelvarde =  (float) sum / n;
    printf("Medelvardet: %.1f\n" ,medelvarde);
}

float median(int v[] ,int n) 
{
    for (int i=0;i<n-1;i++)
    {
        for (int j=0;i<n-i-1;i++)
        {
            if (v[j] > v[j+1])
            {
                int tmp = v[j];
                v[j] = v[j+1];
                v[j+1] = tmp;
            }
        }
    }
    if (n % 2 == 1)
    {
        int i = n / 2;
        int median = v[i];
        printf("Median: %d\n" ,median);
    }
    else 
    {
        int i = n / 2, j = i - 1;
        float median = (float) (v[i] + v[j]) / 2;
        printf("Median: %.1f\n" ,median);
    }
    }
    int typvarde(int v[] ,int n)
    {   
        int maxFrekvens=1;
        int raknaFrekvens[41] = {0};
        for(int i=0;i<n;i++)
        {
            raknaFrekvens[v[i]]++;
            if (raknaFrekvens[v[i]] > maxFrekvens)
            {
                maxFrekvens = raknaFrekvens[v[i]];
            }
        }
        printf("typvarde: ");
        int forst = 1;
        for (int i=20;i<=40;i++)
        {
            if (raknaFrekvens[i] == maxFrekvens)
            {
                
                if (forst==0)
                {
                    printf(", ");
                }
                printf("%d" ,i);
                forst = 0;
            }
        }
    }


    