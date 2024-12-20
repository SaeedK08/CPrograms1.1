#include <stdio.h>
#include <string.h>
#define WORDLENGTH 30
#define MAX 100
struct car
{
    char model[WORDLENGTH];
    int year;
    int mileage;
};

typedef struct car Car;

Car createCar(char model[], int year, int mileage)
{
    Car c;
    strcpy(c.model, model);
    c.year = year;
    c.mileage = mileage;
    return c;
}
void registCar(Car reg[], int *pNrOfCars)
{
    char model[WORDLENGTH], answer[WORDLENGTH] = "yes";
    int year, mileage;
    while (strcmp(answer, "yes") == 0)
    {
        printf("Enter model: \n");
        scanf("%s%*c", model);
        printf("Enter year: \n");
        scanf("%d", &year);
        printf("Enter milage: \n");
        scanf("%d", &mileage);
        reg[*pNrOfCars] = createCar(model, year, mileage);
        (*pNrOfCars)++;
        printf("Do you wamt to continue? (yea/no)\n");
        scanf("%s%*c", answer);
    }
}
void printCarRegister(Car reg[], int nrOfCars)
{
    for (int i = 0; i < nrOfCars; i++)
    {
        printf("Model: %s, Year: %d, Mileage: %d\n", reg[i].model, reg[i].year, reg[i].mileage);
    }
}
void increaseMile(Car carReg[])
{
    int position, miles;
    printf("Enter the car position in the register:");
    scanf("%d" ,&position);
    printf("How many miles do you want to add: ");
    scanf("%d" ,&miles);
    carReg[position].mileage += miles;    
}
int main(void)
{
    int nrOfCars = 0, choice;
    Car carRegister[nrOfCards];
    do
    {
        printf("(1) Register cars\n");
        printf("(2) Print all cars\n");
        printf("(3) Increase mileage\n");
        printf("(4) Shutdown\n");
        scanf("%d" ,&choice);
        switch (choice)
        {
        case 1:
            registCar(carRegister, &nrOfCars);
            break;
        case 2:
            if(nrOfCars == 0)
            printf("NO registered cars\n");
            else
            printCarRegister(carRegister, nrOfCars);
            break;
        case 3:

            increaseMile(carRegister);
            break;
        }
    } while (choice != 4);
    return 0;
}