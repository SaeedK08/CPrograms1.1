#include <stdio.h>
#define ROW 5
#define COLUMN 5
int main (void)
{
    int a [ROW] [COLUMN];
    int i, j;
    int countRow [ROW], countColumn [COLUMN];
    for (i=0;i<ROW;i++)
    {
        printf("Enter row %d:\n" ,i+1);
        for (j=0;j<COLUMN;j++)
        {
        scanf("%d" ,&a[i] [j]);
        }
    }
    for (i=0;i<ROW;i++)
    {
        int rowSum = 0;
        for (j=0;j<COLUMN;j++)
        {
            rowSum = rowSum + a[i] [j];
        }
        countRow[i] = rowSum;
    }
    for (j=0;j<COLUMN;j++)
    {
        int columnSum = 0;
        for (i=0;i<ROW;i++)
        {
            columnSum = columnSum + a[i][j];
        }
        countColumn[j] = columnSum;
    }
    printf("Row toatel:");
    for (i=0;i<ROW;i++)
    {
        printf("%d " ,countRow[i]);
    }
    printf("\n");
    printf("Column toatel:");
    for(int j=0;j<COLUMN;j++)
    {
        printf("%d " ,countColumn[j]);
    }

}