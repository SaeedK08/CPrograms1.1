#include <stdio.h>
int main(void)
{
    int time = 0, throttle;
    float velocity=-25, height=250;
    printf("Lunar decent challege!\n");
    printf("You will pilot a lunar decent the last 250m.\n");
    printf("Each turn represents 1-second decent time.\n");
    printf("Set the throttle for each turn (0-100)\n");
    printf("Time   Height   Velocity  Throttle?\n");
    while(height>0)
    {
        printf(" %d     %6.1f    %6.1f    " ,time ,height ,velocity);
        scanf("%d" ,&throttle);
        height = height+velocity+(0.1*throttle-1.5)/2.0;
        velocity = velocity + (0.1*throttle-1.5); 
        time++;
        
    }
     
    if (velocity < -2)
    {
        printf("\nFAILED! crash landing at %1.1f m/s\n" ,velocity);
    }
    else
    {
        printf("\nMission succeeded! we landed at the moon.\n");
    } 
    return 0;
}