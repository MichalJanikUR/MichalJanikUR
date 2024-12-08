#include <stdio.h>

int main()
{
    int tab[5][5] = { {5, 2, 8, 2, 7}, {9, 3, 5, 1, 4}, {6, 0, 3, 9, 2}, {1, 8, 3, 6, 9}, {2, 9, 4, 3, 6} }, suma = 0;
    int rozmX = sizeof(tab) / sizeof(tab[0]); //wiersz X
    int rozmY = sizeof(tab[0]) / sizeof(tab[0][0]); //kolumna X

    if(rozmX == rozmY)
    {
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                if(i == j) suma += tab[i][j];
                printf("%d ", tab[i][j]);
            }
            printf("\n");
        }

        printf("\nSuma elementow przekatnej: %d", suma);
    }
    else printf("Macierz nie jest kwadratowa!");

    return 0;
}
