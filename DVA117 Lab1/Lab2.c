#include "Lab2.h"

void Lab2_1()
{
    int tal, minstaTal, storstaTal, summa, antalTal;
    double medelvarde;
    int loopa = 1;
    char inmatning[10];

    do
    {
        tal = 0; minstaTal = 0; storstaTal = 0; summa = 0; medelvarde = 0; antalTal = 0;

        printf("Mata in heltal, så många du vill. Avsluta genom att mata in ett negativt tal.\n");
        do
        {
            if (scanInt(&tal))
            {
                if (tal < 0)
                    break;
                if (antalTal == 0)
                    minstaTal = tal;
                if (tal < minstaTal)
                    minstaTal = tal;
                if (tal > storstaTal)
                    storstaTal = tal;
                summa += tal;
                antalTal++;
                medelvarde = (double)summa / (double)antalTal;
            }
            else
                printf("Felaktig inmatning, försök igen: ");
        } while (1);

        if (antalTal == 0)
            printf("Du matade inte in några tal alls! Bättre lycka nästa gång.\n");
        else
        {
            printf("Det minsta talet du matade in är: %d\n", minstaTal);
            printf("Det största talet du matade in är: %d\n", storstaTal);
            printf("Summan av talen du matade in är: %d\n", summa);
            printf("Medelvärdet av talen du matade in är: %f\n", medelvarde);
        }

        printf("\n\nVill du köra en gång till? ");
        scanString(inmatning, 9);

        for (int i = 0; inmatning[i]; i++)
            inmatning[i] = tolower(inmatning[i]);

        if (strcmp(inmatning, "ja") != 0 && strcmp(inmatning, "yes") != 0 && strcmp(inmatning, "1") != 0 && strcmp(inmatning, "j") != 0 && strcmp(inmatning, "y") != 0)
        {
            printf("Tolkar det som ett nej.\n");
            loopa = 0;
        }
    } while (loopa);
}

float KonverteraValuta(float svenskaKronor, float valutaKurs)
{
    return svenskaKronor * valutaKurs;
}


void Lab2_2()
{
    float svenskaKronor = 0;

    printf("Mata in antal svenska kronor att omvandla till Euro: ");
    scanFloat(&svenskaKronor);

    printf("%f svenska kronor motsvarar %f Euro.\n", svenskaKronor, KonverteraValuta(svenskaKronor, 0.1003f));
}

void Lab2_3()
{
    char inmatning[10];
    int loopa = 1;
    int slumptal = 0;
    int gissning = 0;

    srand(time(NULL));

    do
    {
        slumptal = rand() % 100;
        printf("Datorn har semi-slumpmässigt tagit fram ett tal mellan 0 och 100. Vilket då?\n");
        do
        {
            printf("Gissning: ");
            while (!scanInt(&gissning))
                printf("Felaktig inmatning! Försök igen: ");

            if (gissning < slumptal)
                printf("Du gissade för lågt! Försök igen.\n");
            else if (gissning > slumptal)
                printf("Du gissade för högt! Försök igen.\n");
            else
            {
                printf("Rätt! Bra jobbat!\n");
                break;
            }
        } while (1);

        printf("\n\nVill du köra en gång till? ");
        scanString(inmatning, 9);

        for (int i = 0; inmatning[i]; i++)
            inmatning[i] = tolower(inmatning[i]);

        if (strcmp(inmatning, "ja") != 0 && strcmp(inmatning, "yes") != 0 && strcmp(inmatning, "1") != 0 && strcmp(inmatning, "j") != 0 && strcmp(inmatning, "y") != 0)
        {
            printf("Tolkar det som ett nej.\n");
            loopa = 0;
        }
    } while (loopa);
}