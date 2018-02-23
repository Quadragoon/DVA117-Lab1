#include <stdio.h>
#include <locale.h>
#include "myInputManager.h"

int main(void)
{
    setlocale(LC_ALL, "");
    int val = 0;

    while (1)
    {
        system("cls");


        printf("Vilken labb vill du se? ");
        while (!scanInt(&val))
            printf("Felaktig inmatning! Försök igen: ");

        switch (val)
        {
        case 1:
            printf("Vilken del av labben? (2, 3, eller 4) ");
            while (!scanInt(&val))
                printf("Felaktig inmatning! Försök igen: ");
            switch (val)
            {
            case 2:
                Lab1_2();
                break;
            case 3:
                Lab1_3();
                break;
            case 4:
                Lab1_4();
                break;
            default:
                printf("Felaktig inmatning! Vi börjar om från början...\n");
            }
            break;
        case 2:
            printf("Vilken del av labben? (1, 2, eller 3) ");
            while (!scanInt(&val))
                printf("Felaktig inmatning! Försök igen: ");
            switch (val)
            {
            case 1:
                Lab2_1();
                break;
            case 2:
                Lab2_2();
                break;
            case 3:
                Lab2_3();
                break;
            default:
                printf("Felaktig inmatning! Vi börjar om från början...\n");
            }
            break;
        case 3:
            printf("Vilken del av labben? (1, 2, eller 3) ");
            while (!scanInt(&val))
                printf("Felaktig inmatning! Försök igen: ");
            switch (val)
            {
            case 1:
                Lab3_1();
                break;
            case 2:
                Lab3_2();
                break;
            case 3:
                Lab3_3();
                break;
            default:
                printf("Felaktig inmatning! Vi börjar om från början...\n");
            }
            break;
        case 4:
            printf("Vilken del av labben? (1 eller 2) ");
            while (!scanInt(&val))
                printf("Felaktig inmatning! Försök igen: ");
            switch (val)
            {
            case 1:
                Lab4_1();
                break;
            case 2:
                Lab4_2();
                break;
            default:
                printf("Felaktig inmatning! Vi börjar om från början...\n");
            }
            break;
        default:
            printf("Felaktig inmatning! Vi börjar om från början...\n");
            break;
        }
        system("pause");
    }

	return 0;
}