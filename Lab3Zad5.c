#include <stdio.h>

int main()
{
    int tab[10], rozmiar = sizeof(tab) / sizeof(tab[0]);

    printf("Podaj pierwsza wartosc tablicy: ");
    scanf_s("%d", &tab[0]);
    printf("\nPodaj druga wartosc tablicy: ");
    scanf_s("%d", &tab[1]);

    for(int i = 2; i < rozmiar; i++)
    {
        tab[i] = tab[i-1] + tab[i-2];
    }

    for(int i = 0; i < rozmiar; i++)
    {
        printf("%d ",tab[i]);
    }

    return 0;
}
