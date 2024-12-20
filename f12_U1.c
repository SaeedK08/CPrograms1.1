#include <stdio.h>
#include <string.h>
#define WORDLENGTH 40
#define MAX 10
typedef struct account
{
    char name[WORDLENGTH];
    int balance;
}Account;
Account createAccount(char name[], int n)
{
    Account account;
    strcpy(account.name, name);
    account.balance = n;
    return account;
}
void printAccount(Account a)
{
    printf("%s  %4d kr\n" ,a.name, a.balance);
}
void transfer(Account *pAcc1, Account *pAcc2)
{
    pAcc2->balance = pAcc1->balance + pAcc2->balance;
    pAcc1->balance -= pAcc1->balance;

} 
int main(void)
{
    char name1[] = "Simean Singh";
    char name2[] = "Mark Asplund";
    int balance1 = 3210, balance2 = 210;
    Account account1,account2;
    account1 = createAccount(name1, balance1);
    account2 = createAccount(name2, balance2);
    printAccount(account1);
    printAccount(account2);
    transfer(&account1, &account2);
    printAccount(account1);
    printAccount(account2);
}