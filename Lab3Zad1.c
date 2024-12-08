#include <stdio.h>

#define ROZMIAR 10

int main()
{
    int tab[ROZMIAR], x = 3;

    for (int i = 0; i < ROZMIAR; i++)
    {
        tab[i] = x;
        printf("%d ", tab[i]);
        x += 3;
    }
    return 0;
}


