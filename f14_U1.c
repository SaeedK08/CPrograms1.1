#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
typedef struct card
{
    char cardLetter;
    int matched;
} Card;
int numControl(int number, int lowerNum, int upperNum);
void createCards(Card c[], int nrOfCards);
void shuffle(Card c[], int nrOfCards);
void printCards(Card c[], int nrOfCards);
int main(void)
{
    srand(time(NULL));
    int nrOfTries = 0, nrOfCards, nrOfPairs;
    int choice1, choice2;
    do
    {
        printf("Valj antal kort (2-16): \n");
        scanf("%d", &nrOfCards);
    } while (numControl(nrOfCards, 2, 16) == 0 || nrOfCards % 2 != 0);
    nrOfPairs = nrOfCards / 2;
    Card cards[nrOfCards];
    createCards(cards, nrOfCards);
    shuffle(cards, nrOfCards);
    printCards(cards, nrOfCards);
    while (nrOfPairs > 0)
    {
        printf("Kort: ");
        for (int i = 0; i < nrOfCards; i++)
        {
            int cardNr = i + 1;
            if (cards[i].matched == 0)
                printf("%d, ", cardNr);
        }
        printf("\n");
        printf("Vilka kort vill du vanda? ");
        scanf("%d %d", &choice1, &choice2);
        if (numControl(choice1, 1, nrOfCards) == 1 && numControl(choice2, 1, nrOfCards) == 1 && choice1 != choice2)
        {
            if (cards[choice1 - 1].matched == 0 && cards[choice2 - 1].matched == 0)
            {
                if (cards[choice1 - 1].cardLetter == cards[choice2 - 1].cardLetter)
                {
                    cards[choice1 - 1].matched = 1;
                    cards[choice2 - 1].matched = 1;
                    nrOfPairs--;
                    printf("Du fick paret %c\n", cards[choice1 - 1].cardLetter);
                }
                else
                {
                    printf("Du fick %c och %c\n", cards[choice1 - 1].cardLetter, cards[choice2 - 1].cardLetter);
                }
                nrOfTries++;
            }
            else
                printf("Felaktigt val.\n");
        }
        else
            printf("Felaktigt val\n");
    }
    printf("Du anvande %d turer\n", nrOfTries);
}
void createCards(Card c[], int nrOfCards)
{
    char ch = 'A';
    for (int i = 0; i < nrOfCards; i++)
    {
        c[i].cardLetter = ch;
        c[i + 1].cardLetter = ch;
        c[i].matched = 0;
        c[i + 1].matched = 0;
        ch++;
        i++;
    }
}
void shuffle(Card c[], int nrOfCards)
{
    for (int i = 0; i < nrOfCards; i++)
    {

        int j = rand() % nrOfCards;
        Card tmp = c[i];
        c[i] = c[j];
        c[j] = tmp;
    }
}
void printCards(Card c[], int nrOfCards)
{
    for (int i = 0; i < nrOfCards; i++)
    {
        printf("%c %d, ", c[i].cardLetter, c[i].matched);
    }
}
int numControl(int number, int lowerNum, int upperNum)
{
    if (number <= upperNum && number >= lowerNum)
        return 1;
    else
        return 0;
}
