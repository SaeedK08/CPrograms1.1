#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NAMELENGTH 30
#define MAXPLAYERS 8
typedef struct player
{
    char name[NAMELENGTH];
    int score;
} Player;
void initiatePlayers(Player pl[], int nrOfPlayers);
void printScore(Player pl[], int nrOfPlayers);
void playGame(Player *pPlayers);
int turnToPlay(int nrOfPlayers, int activePlayer);
int main(void)
{
    int nrOfPlayers;
    Player players[MAXPLAYERS];
    srand(time(NULL));
    printf("Ange antal spelare: ");
    scanf("%d" ,&nrOfPlayers);
    initiatePlayers(players,nrOfPlayers);
    int activePlayer = rand()%nrOfPlayers;
    while (1)
    {
        printScore(players,nrOfPlayers);
        playGame(&players[activePlayer]);
        if (players[activePlayer].score >= 40)
            break;
        else
            activePlayer = turnToPlay(nrOfPlayers,activePlayer);
    }
    printScore(players, nrOfPlayers);
    printf("%s vinner partiet\n",players[activePlayer]);
}
void initiatePlayers(Player pl[], int nrOfPlayers)
{
    for (int i = 0; i < nrOfPlayers; i++)
    {
        printf("Ange spelare %d: ", i + 1);
        scanf(" %s", pl[i].name);
        pl[i].score = 0;
    }
}
void printScore(Player pl[], int nrOfPlayers)
{
    for (int i = 0; i < nrOfPlayers; i++)
    {
        printf("%s  %d p\t", pl[i].name, pl[i].score);
    }
    printf("\n");
}
void playGame(Player *pPlayers)
{
    char answer;
    int throwResult, roundScore = 0;
    do
    {
        throwResult = rand() % 6 + 1;
        if (throwResult == 1)
        {
            roundScore = 0;
            printf("%s far %d och har denna omgang %d.\n", pPlayers->name, throwResult, roundScore);
            break;
        }
        roundScore += throwResult;
        printf("%s far %d och har denna omgang %d. Kasta igen (j/n)? " ,pPlayers->name,throwResult,roundScore);
        scanf(" %c", &answer);
    } while (answer != 'n');
    pPlayers->score += roundScore;
}
int turnToPlay(int nrOfPlayers ,int activePlayer)
{
    nrOfPlayers--;
    if(activePlayer==nrOfPlayers)
    {
        return 0;
    }
    else{
        activePlayer++;
        return activePlayer; 
    }
}