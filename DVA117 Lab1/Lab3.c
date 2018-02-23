#include "Lab3.h"

/*void PrintSwedishString(char string[])
{
    int i = 0;
    while (string[i] != '\0')
    {
        if (string[i] == -122)
        {
            putchar('\xE5');
            i++;
        }
        else if (string[i] == -124)
        {
            putchar('\xE4');
            i++;
        }
        else if (string[i] == -108)
        {
            putchar('\xF6');
            i++;
        }
        else if (string[i] == -113)
        {
            putchar('\xC5');
            i++;
        }
        else if (string[i] == -114)
        {
            putchar('\xC4');
            i++;
        }
        else if (string[i] == -103)
        {
            putchar('\xD6');
            i++;
        }
        else
        {
            putchar(string[i]);
            i++;
        }
    }
}*/

void Lab3_1()
{
    int slumptal[10];
    char inmatning[10];
    int loopa = 1;

    srand(time(NULL));

    do
    {
        int talAttFinna = 0;
        int antalFunna = 0;

        for (int i = 0; i < 10; i++)
        {
            slumptal[i] = rand() % 10 + 1;
            printf("Tal: %d\n", slumptal[i]);
        }

        printf("\nVad ska jag söka efter? ");
        while (!scanInt(&talAttFinna) || (talAttFinna < 1 || talAttFinna > 10))
            printf("Felaktig inmatning! Försök igen: ");

        for (int i = 0; i < 10; i++)
        {
            if (slumptal[i] == talAttFinna)
                antalFunna++;
        }

        printf("Talet %d förekommer %d gånger.\n", talAttFinna, antalFunna);

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

void SkrivTarning(int siffra, char tarningar[6][3][6])
{
    for (int j = 0; j < 3; j++)
    {
        for (int x = 0; x < 5; x++)
            printf("%c", tarningar[siffra][j][x]);
        printf("%c", '\n');
    }
    printf("%c", '\n');
}

int Summera(int tal[], int size)
{
    int summa = 0;
    for (int i = 0; i < size; i++)
        summa += tal[i];
    return summa;
}

void Lab3_2()
{
    int slumptal[5];
    char inmatning[10];
    int loopa = 1;
    srand(time(NULL));

    char tarningar[6][3][6] = { { { "     " },{ "  *  " },{ "     " } },{ { "*    " },{ "     " },{ "    *" } },{ { "*    " },{ "  *  " },{ "    *" } },
    { { "*   *" },{ "     " },{ "*   *" } },{ { "*   *" },{ "  *  " },{ "*   *" } },{ { "*   *" },{ "*   *" },{ "*   *" } } };

    do
    {
        for (int i = 0; i < 5; i++)
        {
            slumptal[i] = rand() % 6 + 1;
            SkrivTarning(slumptal[i] - 1, tarningar);
        }

        printf("Summa (");
        for (int i = 0; i < 5; i++)
            if (i < 4)
                printf("%d+", slumptal[i]);
            else
                printf("%d", slumptal[i]);
        printf(") = %d.\n", Summera(slumptal, 5));

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

int IsPalindrome(char inputString[])
{
    int i = 0;
    while (inputString[i] != '\0')
        i++;
    i--;
    for (int j = 0; inputString[j] != '\0'; j++)
        if (inputString[j] != inputString[i])
            return 0;
        else
            i--;
    return 1;
}

void FilterStringToOnlyLetters(char inputString[])
{
    char outputString[64];
    int j = 0;

    for (int i = 0; inputString[i] != '\0'; i++)
    {
        if (IsSwedishAlpha(inputString[i]))
        {
            outputString[j] = inputString[i];
            j++;
        }
    }

    int i;
    for (i = 0; i < j; i++)
    {
        inputString[i] = outputString[i];
    }
    inputString[i] = '\0';
}

void MakeWordLowercase(char inputString[])
{
    int i = 0;
    while (inputString[i] != '\0')
        i++;

    for (int j = 0; j < i; j++)
        inputString[j] = tolower(inputString[j]);
}

void Lab3_3()
{
    char ord[64];
    char inmatning[10];
    int loopa = 1;

    do
    {
        printf("Skriv en fras så kollar vi om det är ett palindrom: ");
        scanString(ord, 64);

        FilterStringToOnlyLetters(ord);
        MakeWordLowercase(ord);

        /*if (IsPalindrome(ord))
        {
            printf("Ja, det är ett palindrom: ");
            PrintSwedishString(ord);
        }*/
        if (IsPalindrome(ord))
            printf("Ja, det är ett palindrom: %s", ord);
        else
            printf("Det är tyvärr inget palindrom.\n");

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