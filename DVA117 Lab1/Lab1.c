#include "Lab1.h"

void Lab1_2()
{
    int tal1;
    int tal2;
    int summa;
    tal1 = 0;
    tal2 = 0;

    printf("Ange ett heltal: ");
    while (!scanInt(&tal1))
        printf("Det där är inte ett heltal! Försök igen: ");

    printf("Ange ytterligare ett heltal: ");
    while (!scanInt(&tal2))
        printf("Det där är inte ett heltal! Försök igen: ");

    summa = tal1 + tal2;

    printf("%d + %d = %d\n", tal1, tal2, summa);
    return;
}

void Lab1_3()
{
    int vinkel;

    while (1)
    {
        printf("Ange en vinkel mellan 0 och 180 grader: ");
        if (scanInt(&vinkel))
        {
            if (vinkel < 90)
                printf("Vinkeln är spetsig.\n");
            else if (vinkel == 90)
                printf("Vinkeln är rät.\n");
            else if (vinkel <= 180)
                printf("Vinkeln är trubbig.\n");
            else
                printf("Vinkeln är inkorrekt angiven.\n");
            return;
        }
        else
            printf("Inkorrekt inmatning, försök igen.\n");
    }
}

void Lab1_4()
{
    int siffra;
    int loopa = 1;
    char inmatning[10];

    do
    {
        printf("Ange en siffra mellan 0 och 5: ");
        while (!scanInt(&siffra))
            printf("Det där är inte ett heltal! Försök igen: ");

        if (siffra >= 0 && siffra < 6)
        {
            switch (siffra)
            {
            case 0:
                printf("0 = -----\n");
                break;
            case 1:
                printf("1 = .----\n");
                break;
            case 2:
                printf("2 = ..---\n");
                break;
            case 3:
                printf("3 = ...--\n");
                break;
            case 4:
                printf("4 = ....-\n");
                break;
            case 5:
                printf("5 = .....\n");
                break;
            default:
                printf("Felaktig inmatning!\n");
                break;
            }

            printf("Vill du köra en gång till? ");
            scanString(inmatning, 9);

            for (int i = 0; inmatning[i]; i++)
                inmatning[i] = tolower(inmatning[i]);

            if (strcmp(inmatning, "ja") != 0 && strcmp(inmatning, "yes") != 0 && strcmp(inmatning, "1") != 0 && strcmp(inmatning, "j") != 0 && strcmp(inmatning, "y") != 0)
            {
                printf("Tolkar det som ett nej.\n");
                loopa = 0;
            }
        }
        else
            printf("Inkorrekt inmatning, försök igen.\n");
    } while (loopa);
}