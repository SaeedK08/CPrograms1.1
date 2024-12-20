#include <stdio.h>
#define MAX 100
/*typedef struct boxes
{
    int capacity;
    int items;
} Box;*/
void fillItems(int items[], int capacity, int *pNrOfItems);
void print(int v[], int n);
int countBoxes(int items[], int nrOfitems, int capacity);
int main(void)
{
    int capacity, nrOfItems = 0;
    int items[MAX];
    while (1)
    {
        printf("Ange ladstorlek (1-10kg) : ");
        scanf("%d", &capacity);
        if (capacity < 1 || capacity > 10)
            printf("Felaktig inmatning\n");
        else
            break;
    }
    fillItems(items, capacity ,&nrOfItems);
    int nrOfboxes = countBoxes(items,nrOfItems,capacity);
    printf("Varorna ");
    print(items, nrOfItems);
    printf("kan packas i %d lador" ,nrOfboxes);
}
void fillItems(int items[], int capacity, int *pNrOfItems)
{
    for (int i = 0; i < 100; i++)
    {
        while (1)
        {
            printf("Ange vara (1-%dkg) eller 0 for att avsluta: ", capacity);
            scanf("%d", &items[i]);
            if (items[i] == 0)
                break;
            else if (items[i] < 1 || items[i] > capacity)
                printf("Felaktig inmatning\n");
            else
                break;
        }
        if (items[i] == 0)
            break;
        else
            (*pNrOfItems)++;
    }
}
void print(int v[] ,int n)
{
    int coma = 0;
    printf("(");
    for(int i=0;i<n;i++)
    {
        if(coma)
            printf(",");
        printf("%d" ,v[i]);
        coma = 1;
    }
    printf(") ");
}
int countBoxes(int items[], int nrOfitems, int capacity)
{
    int nrOfBoxes = 1;
    int combineItems[nrOfitems];
    for(int i=0;i<nrOfitems;i++)
    {
        combineItems[i] = items[i];
    }
    for(int i=0;i<nrOfitems-1;i++)
    {
        if(combineItems[i]+combineItems[i+1] > capacity)        
            nrOfBoxes++;
        else 
            combineItems[i+1] += combineItems[i];
    }
    return nrOfBoxes;
}

