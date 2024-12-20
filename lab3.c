#include <stdio.h>
#include <string.h>
#define FILENAME 41
#define IDNUMBER 12
#define NAME 41
#define MAXPICS 10
#define MAXPATIENTS 1000
typedef struct patient
{
    char personalIdNum[IDNUMBER];
    char name[NAME];
    int picReferences[MAXPICS];
    int nrOfPics;
} Patient;
void loadPatientsFromFile(Patient patients[], int *pNrOfPatients, char fileName[]);
void databaseManegment(Patient patients[], int *pNrOfPatients);
void savePatientsToFile(Patient patients[], int nrOfPatients, char fileName[]);
void RegisterNewPatients(Patient patients[], int *pNrOfPatients);
void viewPatients(Patient patients[], int nrOfPatients);
int searchForPatients(Patient patients[], int nrOfPatients, int menuChoice);
void addPictures(Patient patients[], int nrOfPatients);
void sortPatients(Patient patients[], int nrOfPatients);
int compareBirthDates(char s1[], char s2[]);
void unregisterPatients(Patient patients[], int *pNrOfPatients);
int searchPatientsByIdNum(Patient patients[], int nrOfPatients, int menuChoice);
int searchPatientsByName(Patient patients[], int nrOfPatients, int menuChoice);
int searchPatientsByPicRef(Patient patients[], int nrOfPatients, int menuChoice);
void convertToLowerCase(char s[]);
void viewSearchedPatient(Patient patients[], int patient, int quit);
int checkUsedIdNum(Patient patients[], int nrOfPatients, char IdNum[]);
int checkUsedPicRef(Patient patients[], int nrOfPatients, int newPicRef);
int main(void)
{
    int nrOfPatients = 0;
    char fileName[FILENAME];
    Patient patients[MAXPATIENTS];
    printf("Patientjournalsystem\n");
    loadPatientsFromFile(patients, &nrOfPatients, fileName);
    databaseManegment(patients, &nrOfPatients);
    savePatientsToFile(patients, nrOfPatients, fileName);
}
void loadPatientsFromFile(Patient patients[], int *pNrOfPatients, char fileName[])
{
    int nrOfPatientsInFile;
    FILE *fp;
    printf("Vilken fil vill du anvanda: ");
    scanf(" %s", fileName);
    fp = fopen(fileName, "r");
    if (fp != NULL)
    {
        fscanf(fp, "%d", &nrOfPatientsInFile);
        if (nrOfPatientsInFile >= MAXPATIENTS)
            (*pNrOfPatients) = MAXPATIENTS;
        else
            (*pNrOfPatients) = nrOfPatientsInFile;
        printf("Antal patienter: %d\n", (*pNrOfPatients));
        for (int i = 0; i < *pNrOfPatients; i++)
        {
            patients[i].nrOfPics = 0;
            fscanf(fp, " %s", patients[i].personalIdNum);
            while (fscanf(fp, "%d", &patients[i].picReferences[patients[i].nrOfPics]))
            {
                patients[i].nrOfPics++;
            }
            fscanf(fp, " %[^\n]%*c", patients[i].name);
        }
        fclose(fp);
    }
    else
        printf("Skapar filen %s\n", fileName);
    return;
}
void databaseManegment(Patient patients[], int *pNrOfPatients)
{
    int menuChoice;
    while (1)
    {
        printf("Huvudmeny\n\t"
               "1) Registrera nya patienter\n\t"
               "2) Skriva ut alla patienter\n\t"
               "3) Soka efter patienter\n\t"
               "4) Lagg till bilder\n\t"
               "5) Sortera patienter\n\t"
               "6) Avregistrera patienter\n\t"
               "7) Avsluta programmet\n");
        printf("Ange alternativ: ");
        scanf("%d", &menuChoice);
        if (menuChoice == 7) break;
        switch (menuChoice)
        {
        case 1:
            RegisterNewPatients(patients, pNrOfPatients);
            break;
        case 2:
            viewPatients(patients, *pNrOfPatients);
            break;
        case 3:
            searchForPatients(patients, *pNrOfPatients, 0);
            break;
        case 4:
            addPictures(patients, *pNrOfPatients);
            break;
        case 5:
            sortPatients(patients, *pNrOfPatients);
            break;
        case 6:
            unregisterPatients(patients, pNrOfPatients);
            break;
        }
    }
    return;
}
void savePatientsToFile(Patient patients[], int nrOfPatients, char fileName[])
{
    FILE *fp;
    fp = fopen(fileName, "w");
    if (fp != NULL)
    {
        fprintf(fp, "%d\n", nrOfPatients);
        for (int i = 0; i < nrOfPatients; i++)
        {
            fprintf(fp, "%s \t", patients[i].personalIdNum);
            for (int j = 0; j < patients[i].nrOfPics; j++)
            {
                fprintf(fp, "%d ", patients[i].picReferences[j]);
            }
            fprintf(fp, "\t%s", patients[i].name);
            fprintf(fp, "\n");
        }
        fclose(fp);
        printf("Sparar patientdata i %s\n", fileName);
        printf("Avslutar\n");
    }
    else
        printf("Lyckades ej oppna filen\n");
}
void RegisterNewPatients(Patient patients[], int *pNrOfPatients)
{
    char readIdNum[IDNUMBER];
    int newPicRef;
    while (1)
    {
        if (*pNrOfPatients >= MAXPATIENTS)
        {
            printf("Inga fler patienter kan tillagas.\n");
            return;
        }
        do
        {
            printf("Ange personnummer (q for att avsluta) : ");
            scanf("%s", readIdNum);
            if (strcmp(readIdNum, "q") == 0)
            {
                printf("Avslutar registrerig\n");
                return;
            }
            if (checkUsedIdNum(patients, *pNrOfPatients, readIdNum))
                printf("Redan registrerat.\n");
        } while (checkUsedIdNum(patients, *pNrOfPatients, readIdNum));
        strcpy(patients[*pNrOfPatients].personalIdNum, readIdNum);
        printf("Ange namn: ");
        scanf(" %[^\n]%*c", patients[*pNrOfPatients].name);
        patients[*pNrOfPatients].nrOfPics = 0;
        while (1)
        {
            if (patients[*pNrOfPatients].nrOfPics >= MAXPICS)
            {
                printf("Antalet referenser fyllt.\n");
                break;
            }
            printf("Ange bildreferens (eller 0 for att avsluta) : ");
            scanf("%d", &newPicRef);
            if (newPicRef == 0) break;
            if (checkUsedPicRef(patients, *pNrOfPatients, newPicRef))
                printf("Referensen finns redan!\n");
            else
            {
                patients[*pNrOfPatients].picReferences[patients[*pNrOfPatients].nrOfPics] = newPicRef;
                patients[*pNrOfPatients].nrOfPics++;
            }
        }
        (*pNrOfPatients)++;
    }
}
void viewPatients(Patient patients[], int nrOfPatients)
{
    if (nrOfPatients == 0)
    {
        printf("Databasen ar tom.\n");
        return;
    }
    printf("Personnummer\t  Namn\t\t     Bildreferenser\n");
    for (int i = 0; i < 60; i++) printf("_");
    printf("\n");
    for (int i = 0; i < nrOfPatients; i++)
    {
        printf("%s\t ", patients[i].personalIdNum);
        printf("%-20s", patients[i].name);
        printf("[");
        for (int j = 0; j < patients[i].nrOfPics; j++)
        {
            if (j > 0) printf(", ");
            printf("%d", patients[i].picReferences[j]);
        }
        printf("]\n");
    }
    printf("\n");
}
int searchForPatients(Patient patients[], int nrOfPatients, int menuChoice)
{
    int typeOfSearch, patient;
    if (nrOfPatients == 0)
    {
        printf("Databasen ar tom.\n");
        return 0;
    }
    do
    {
        printf("Sok pa personnummer(1), namn(2), bildreferens(3), avslutar(4): ");
        scanf("%d", &typeOfSearch);
        switch (typeOfSearch)
        {
        case 1:
            patient = searchPatientsByIdNum(patients, nrOfPatients, menuChoice);
            if (menuChoice == 1 && patient != -1) return patient;
            break;
        case 2:
            patient = searchPatientsByName(patients, nrOfPatients, menuChoice);
            if (menuChoice == 1 && patient != -1) return patient;
            break;
        case 3:
            patient = searchPatientsByPicRef(patients, nrOfPatients, menuChoice);
            if (menuChoice == 1 && patient != -1) return patient;
            break;
        }
    } while (typeOfSearch != 4);
    if (!menuChoice)
        printf("Avslutar sokning\n");
    return -1;
}
void addPictures(Patient patients[], int nrOfPatients)
{
    int newPicRef, patient;
    if (nrOfPatients == 0)
    {
        printf("Databaen ar tom.\n");
        return;
    }
    patient = searchForPatients(patients, nrOfPatients, 1);
    if (patient != -1)
    {
        while (1)
        {
            if (patients[patient].nrOfPics >= MAXPICS)
            {
                printf("Antalet referenser fyllt\n");
                break;
            }
            printf("Ange bildreferens (eller 0 for att avsluta) : ");
            scanf("%d", &newPicRef);
            if (newPicRef == 0) break;
            if (checkUsedPicRef(patients, nrOfPatients, newPicRef))
                printf("Referensen finns redan!\n");
            else
            {
                patients[patient].picReferences[patients[patient].nrOfPics] = newPicRef;
                patients[patient].nrOfPics++;
            }
        }
        printf("Avslutar lagga till bilder\n");
        return;
    }
    else return;
}
void sortPatients(Patient patients[], int nrOfPatiets)
{
    if (nrOfPatiets == 0)
    {
        printf("Databasen ar tom.\n");
        return;
    }
    int choice;
    Patient tmp;
    printf("Sortera patienter efter personnummer(1), namn(2), avsluta(3): ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        for (int i = 0; i < nrOfPatiets - 1; i++)
        {
            for (int j = 0; j < nrOfPatiets - 1 - i; j++)
            {
                if (compareBirthDates(patients[j].personalIdNum, patients[j + 1].personalIdNum) > 0)
                {
                    tmp = patients[j];
                    patients[j] = patients[j + 1];
                    patients[j + 1] = tmp;
                }
            }
        }
        printf("Sorterar patienter efter personnummer\n");
        return;
    case 2:
        for (int i = 0; i < nrOfPatiets - 1; i++)
        {
            for (int j = 0; j < nrOfPatiets - 1 - i; j++)
            {
                if (strcmp(patients[j].name, patients[j + 1].name) > 0)
                {
                    tmp = patients[j];
                    patients[j] = patients[j + 1];
                    patients[j + 1] = tmp;
                }
            }
        }
        printf("Sorterar patienter efter namn\n");
        return;
    default:
        return;
    }
}
void unregisterPatients(Patient patients[], int *pNrOfPatients)
{
    char choice;
    int patient;
    if (*pNrOfPatients == 0)
    {
        printf("Databasen ar tom.\n");
        return;
    }
    patient = searchForPatients(patients, *pNrOfPatients, 1);
    if (patient != -1)
    {
        printf("Vill du avregistrera patienten (j/n)?");
        scanf(" %c", &choice);
        if (choice == 'j')
        {
            for (int i = patient; i < *pNrOfPatients - 1; i++)
            {
                patients[i] = patients[i + 1];
            }
            (*pNrOfPatients)--;
            printf("Patienten avregistreras\n");
            return;
        }
        else
        {
            printf("Avbryter avregistrering\n");
            return;
        }
    }
    else return;
}
int searchPatientsByIdNum(Patient patients[], int nrOfPatients, int menuChoice)
{
    char searchedIdNum[IDNUMBER];
    printf("Ange personnummer: ");
    scanf(" %s", searchedIdNum);
    for (int i = 0; i < nrOfPatients; i++)
    {
        if (strcmp(patients[i].personalIdNum, searchedIdNum) == 0)
        {
            viewSearchedPatient(patients, i, 1);
            printf("\n");
            return i;
        }
    }
    printf("Personnumret saknas i databasen.\n");
    if (menuChoice)
        printf("Du fick inte exakt en traff\n");
    return -1;
}
int searchPatientsByName(Patient patients[], int nrOfPatients, int menuChoice)
{
    int nameMatches = 0, patient, quit = 1;
    char searchWord[NAME], name[NAME];
    printf("Ange sokstrang: ");
    scanf(" %s", searchWord);
    convertToLowerCase(searchWord);
    for (int i = 0; i < nrOfPatients; i++)
    {
        strcpy(name, patients[i].name);
        convertToLowerCase(name);
        if (strstr(name, searchWord) != NULL)
        {
            viewSearchedPatient(patients, i, quit);
            patient = i;
            nameMatches++;
            quit = 0;
        }
    }
    printf("\n");
    if (nameMatches == 1) return patient;
    if (menuChoice) printf("Du fick inte exakt en traff.\n");
    return -1;
}
int searchPatientsByPicRef(Patient patients[], int nrOfPatients, int menuChoice)
{
    int searchedPicRef;
    printf("Ange bildreferens: ");
    scanf("%d", &searchedPicRef);
    if (checkUsedPicRef(patients, nrOfPatients, searchedPicRef))
    {
        for (int i = 0; i < nrOfPatients; i++)
        {
            for (int j = 0; j < patients[i].nrOfPics; j++)
            {
                if (patients[i].picReferences[j] == searchedPicRef)
                {
                    viewSearchedPatient(patients, i, 1);
                    printf("\n");
                    return i;
                }
            }
        }
    }
    else
        printf("Bildreferensen saknas i databasen.\n");
    return -1;
}
void convertToLowerCase(char s[])
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] - 'A' + 'a';
    }
}
int compareBirthDates(char s1[], char s2[])
{
    int year1 = (s1[0] - '0') * 10 + (s1[1] - '0');
    int year2 = (s2[0] - '0') * 10 + (s2[1] - '0');
    int month1 = (s1[2] - '0') * 10 + (s1[3] - '0');
    int month2 = (s2[2] - '0') * 10 + (s2[3] - '0');
    int day1 = (s1[4] - '0') * 10 + (s1[5] - '0');
    int day2 = (s2[4] - '0') * 10 + (s2[5] - '0');

    if (year1 >= 24) year1 += 1900;
    else year1 += 2000;
    if (year2 >= 24) year2 += 1900;
    else year2 += 2000;

    if (year1 > year2) return 1;
    else if (year1 == year2 && month1 > month2) return 1;
    else if (year1 == year2 && month1 == month2 && day1 > day2) return 1;
    else return 0;
}
void viewSearchedPatient(Patient patients[], int patient, int quit)
{
    if (quit)
    {
        printf("Personnummer\t  Namn\t\t   Bildreferenser\n");
        for (int i = 0; i < 60; i++) printf("_");
        printf("\n");
    }
    printf("%s\t", patients[patient].personalIdNum);
    printf("%-20s", patients[patient].name);
    printf("[");
    for (int j = 0; j < patients[patient].nrOfPics; j++)
    {
        if (j > 0) printf(", ");
        printf("%d", patients[patient].picReferences[j]);
    }
    printf("]\n");
}
int checkUsedIdNum(Patient patients[], int nrOfPatients, char IdNum[])
{
    for (int i = 0; i < nrOfPatients; i++)
    {
        if (strcmp(patients[i].personalIdNum, IdNum) == 0) return 1;
    }
    return 0;
}
int checkUsedPicRef(Patient patients[], int nrOfPatients, int newPicRef)
{
    for (int i = 0; i <= nrOfPatients; i++)
    {
        for (int j = 0; j < patients[i].nrOfPics; j++)
        {
            if (patients[i].picReferences[j] == newPicRef) return 1;
        }
    }
    return 0;
}
