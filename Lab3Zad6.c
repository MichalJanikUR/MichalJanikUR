#include <stdio.h>

int main()
{
    int tab[20] = {12, 2, 3, 34, 5, 61, 7, -68, 9, 4}, rozmiar = sizeof(tab) / sizeof(tab[0]);

    for(int i = rozmiar / 2; i < rozmiar; i++)
    {
        tab[i] = tab[i - (rozmiar / 2)];
    }

    //pierwsza polowa
    for(int i = 0; i < rozmiar / 2; i++)
    {
        printf("%d ", tab[i]);
    }

    printf("\n\n");

    //druga polowa - skopiowana
    for(int i = rozmiar / 2; i < rozmiar; i++)
    {
        printf("%d ", tab[i]);
    }

    return 0;
}
