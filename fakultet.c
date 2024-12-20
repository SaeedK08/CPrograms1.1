#include <stdio.h> 
int main(void)
{
   int n, i;
   while (n != 0)
   {
   printf("Ange ett tal: \n");
   scanf("%d" ,&n);
   unsigned int faktor=1;
   if (n<0)
   {
      printf("Talet ska vara positivt. \n");
      printf("Avslutar \n");
   }
   else if (n>0)
   {
      for (i=1;i<=n;i++)
      {
         faktor *= i; 
      }
      printf("%d! = %u \n" , n,faktor);
   }
   } 
   printf("Avslutar \n");
}