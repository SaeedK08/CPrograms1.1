#include <stdio.h>
#include <string.h>
#define MAX 10
typedef struct temperature
{
    char date[11];
    float measurments[nrOfCards];
    int nrOfMeasurments;
}Temp;
void printTemp(Temp a);
void concatenate(Temp *pTemp1, Temp *pTemp2);
int main(void)
{
    Temp temperatures1 = {"2021-06-27", {18.7, 19.2, 18.3} ,3};
    Temp temperatures2 = {"2021-06-27", {22.1, 23.4}, 2};
    printTemp(temperatures1);
    concatenate(&temperatures1, &temperatures2);
    printTemp(temperatures1);
}
void printTemp(Temp a)
{
    printf("%s " ,a.date);
    for(int i=0;i<a.nrOfMeasurments;i++)
    {
        printf("%0.1f, " ,a.measurments[i]);
    }
    printf("\n");
}
void concatenate(Temp *pTemp1, Temp *pTemp2)
{
    if (strcmp(pTemp1->date, pTemp2->date)==0)
    {
        int nrOfMeasurmets2 = pTemp2->nrOfMeasurments;
        for(int i=0;i<nrOfMeasurmets2;i++)
        {
            if (pTemp1->nrOfMeasurments < nrOfCards)
            {
                pTemp1->measurments[pTemp1->nrOfMeasurments] = pTemp2->measurments[i];
                pTemp1->nrOfMeasurments ++;
            }
        }
    }
}