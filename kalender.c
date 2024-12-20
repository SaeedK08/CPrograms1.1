#include <stdio.h>
int main(void)
{
int numOfDays, firstday;
printf("Ange antal dagar i manaden: \n");
scanf("%d" ,&numOfDays);
do 
{
printf("Ange forsta dagen i manaden (1-man, 2-tis,...,son-7): \n");
scanf("%d" ,&firstday);
} while(firstday<1||firstday>7);
printf("  m ti  o to  f  l  s\n");
for (int i=1;i<firstday;i++)
{
    printf("   ");
}
int currentposition = firstday;
for (int currentday=1;currentday<=numOfDays;currentday++)
{
    printf("%3d" ,currentday);
    currentposition++;
    if (currentposition>7)
    {
        currentposition = 1;
        printf("\n");
    }
}

}