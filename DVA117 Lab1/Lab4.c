#include "Lab4.h"

int IsSwedishAlpha(int character)
{
    if (character == -122 || character == -124 || character == -108 || character == -113 || character == -114 || character == -103 || isalpha(character))
        return 1;
    else
        return 0;
}

void CountOccurrences(int tal[], int size, int* mostFrequent, int* numberOfOccurrences)
{
    int haveCounted = 0;
    int currentlyCounting = -1;
    int currentCount = -1;

    for (int i = 0; haveCounted < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (tal[j] != -1 && currentlyCounting == -1)
            {
                currentlyCounting = tal[j];
                currentCount = 1;
                tal[j] = -1;
                haveCounted++;
            }
            else if (tal[j] == currentlyCounting)
            {
                currentCount++;
                tal[j] = -1;
                haveCounted++;
            }
        }
        if (currentCount > *numberOfOccurrences)
        {
            *mostFrequent = currentlyCounting;
            *numberOfOccurrences = currentCount;
        }

        currentlyCounting = -1;
    }
}

void Lab4_1()
{
    char inmatning[10];
    int loopa = 1;

    do
    {
        int mostFrequent = 0;
        int numberOfOccurrences = 0;

        int tal[100];
        int inmatatTal;
        int antalInmatade = 0;

        printf("Mata in en mängd positiva heltal, max 100st. Avsluta genom att mata in ett negativt tal.\n");

        do
        {
            printf("Inmatning: ");
            while (scanInt(&inmatatTal) != 1)
                printf("Felaktig inmatning! Försök igen: ");
            if (inmatatTal >= 0)
            {
                tal[antalInmatade] = inmatatTal;
                antalInmatade++;
            }
        } while (inmatatTal >= 0);

        CountOccurrences(tal, antalInmatade, &mostFrequent, &numberOfOccurrences);
        printf("%d förekommer %d gånger.\n", mostFrequent, numberOfOccurrences);

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

void PrintFirstWordOfString(char string[])
{
    int i = 0;
    while (1)
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
        else if (string[i] != ' ' && string[i] != '\0' && IsSwedishAlpha(string[i]))
        {
            putchar(string[i]);
            i++;
        }
        else
            break;
    }
}

char* GetWord(char string[], int wordIndex)
{
    int i = 0;
    int j = 0;
    while (j < wordIndex)
    {
        if (string[i] == '\0')
            return NULL;
        else if (!IsSwedishAlpha(string[i]))
        {
            j++;
            while (!IsSwedishAlpha(string[i]))
            {
                if (string[i] == '\0')
                    return NULL;
                i++;
            }
            i--;
        }
        i++;

    }
    
    return (string + sizeof(char)*i);
}

void PrintWord(char string[], int wordIndex)
{
    char* wordToPrint;
    if (wordToPrint = GetWord(string, wordIndex))
        PrintFirstWordOfString(wordToPrint);
    else
        printf("Invalid word, cannot print!\n");
}

void Lab4_2()
{
    char string[64];
    int whichWordToPrint = 0;

    char inmatning[10];
    int loopa = 1;

    do
    {
        printf("Mata in en sträng: ");
        scanString(string, 64);

        /*for (int i = 0; string[i] != '\0'; i++)
        {
            if ((int)string[i] == -122)
                string[i] = '\x86';
        }*/

        printf("Vilket (noll-indexerat) ord vill du skriva ut? ");
        while (!scanInt(&whichWordToPrint))
            printf("Felaktig inmatning! Försök igen: ");

        PrintWord(string, whichWordToPrint);

        printf("\n\n\nVill du köra en gång till? ");
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