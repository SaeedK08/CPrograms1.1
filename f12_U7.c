#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
typedef struct cards
{
    char type;
    int value;
}Card;
typedef struct  hand
{
    Card cardHand[52];
    int nrOfCards;
}Hand;
void printHand(Hand hand, int num);
void swap(Hand *pHand1, Hand *pHand2);
int main(void)
{
    srand(time(NULL));
    Hand myHand = {{'s',2,'h',12,'r',3,'r',8}, 4};
    Hand yourHand = {{'k',3,'k',4,'k',5,'k',6,'k',7},5};
    printHand(myHand, myHand.nrOfCards);
    printHand(yourHand, yourHand.nrOfCards);
    swap(&myHand, &yourHand);
    printHand(myHand, myHand.nrOfCards);
    printHand(yourHand, yourHand.nrOfCards);
}
void printHand(Hand hand, int num)
{
    for(int i=0;i<num;i++)
    {
        printf("%c %d, " ,hand.cardHand[i].type, hand.cardHand[i].value);
    }
    printf("\n");
}
void swap(Hand *pHand1, Hand *pHand2)
{
    int q = rand()%pHand1->nrOfCards;
    pHand2->cardHand[pHand2->nrOfCards] = pHand1->cardHand[q];
    for(int i=q;i<pHand1->nrOfCards;i++)
    {
        pHand1->cardHand[i] = pHand1->cardHand[i+1];
    }
    pHand2->nrOfCards ++;
    pHand1->nrOfCards --;
}