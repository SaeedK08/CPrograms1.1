#include <stdio.h>
#include <math.h>
#define LENGTH 10
int enter(int v[], int nrOfMeasurments, int n);
void view(int v[], int nrOfMeasurments);
int maxValue(int v[], int nrOfMeasurments);
int minValue(int v[], int nrOfMeasurments);
float avrValue(int v[], int nrOfMeasurments);
void normalizedValues(int v[], int nrOfMeasurments, int j[]);
void compute(int v[], int nrOfMeasurments, int j[]);
int main(void)
{
    int measurments[LENGTH] = {0};
    int normalizedArray[LENGTH] = {0};
    int nrOfMeasurments = 0;
    char choice;
    printf("Measurment tool 2.0\n");
    do
    {
        printf("VERQC? ");
        scanf(" %c", &choice);
        switch (choice)
        {
        case 'e':
            nrOfMeasurments = enter(measurments, nrOfMeasurments, LENGTH);
            break;
        case 'v':
            view(measurments, nrOfMeasurments);
            break;
        case 'c':
            compute(measurments, nrOfMeasurments, normalizedArray);
            break;
        case 'r':
            //for (int i = 0; i < LENGTH; i++)
            //{
              //  measurments[i] = 0;
               // normalizedArray[i] = 0;
            //}
            nrOfMeasurments = 0;
            break;
        }
    } while (choice != 'q');
    printf("Exit measurment tool\n");
    return 0;
}
int enter(int v[], int nrOfMeasurments, int n)
{
    for (int i = nrOfMeasurments; i < n; i++)
    {
        int value;
        printf("Enter measurment #%d (or q to quit): ", i + 1);
        int integerCheck = scanf("%d", &value);
        if (integerCheck)
        {
            v[i] = value;
            nrOfMeasurments++;
        }
        else
        {
            char tmp;
            scanf(" %c", &tmp);
            return nrOfMeasurments;
        }
    }
    return nrOfMeasurments;
}
void view(int v[], int nrOfMeasurments)
{
    if (!nrOfMeasurments)
    {
        printf("No measurments\n");
    }
    else
    {
        printf("[");
        for (int i = 0; i < nrOfMeasurments; i++)
        {
            printf(" %d ", v[i]);
        }
        printf("]\n");
    }
}
int maxValue(int v[], int nrOfMeasurments)
{
    int max = 0;
    for (int i = 0; i < nrOfMeasurments; i++)
    {
        if (v[i] > max)
        {
            max = v[i];
        }
    }
    return max;
}
int minValue(int v[], int nrOfMeasurments)
{
    int min = maxValue(v, nrOfMeasurments);
    for (int i = 0; i < nrOfMeasurments; i++)
    {
        if (v[i] < min)
        {
            min = v[i];
        }
    }
    return min;
}
float avrValue(int v[], int nrOfMeasurments)
{
    int sum = 0;
    for (int i = 0; i < nrOfMeasurments; i++)
    {
        sum += v[i];
    }
    float avrValue = (float)sum / nrOfMeasurments;
    return avrValue;
}
void normalizedValues(int v[], int nrOfMeasurments, int j[])
{
    double avr = avrValue(v, nrOfMeasurments);
    double avrRounded = round(avr);
    for (int i = 0; i < nrOfMeasurments; i++)
    {
        j[i] = v[i] - avrRounded;
    }
}
void compute(int v[], int nrOfMeasurments, int j[])
{
    if (nrOfMeasurments == 0)
    {
        printf("No measurments\n");
    }
    else
    {
        printf("Max value: %d\n", maxValue(v, nrOfMeasurments));
        printf("Min value: %d\n", minValue(v, nrOfMeasurments));
        printf("Avr value: %.2f\n", avrValue(v, nrOfMeasurments));
        normalizedValues(v, nrOfMeasurments, j);
        view(j, nrOfMeasurments);
    }
}
