#include <stdio.h>

int main()
{
    int tab[10], a, rozmiar = sizeof(tab) / sizeof(tab[0]);

	for (int i = rozmiar-1; i >= 0; i--)
	{
		printf("Podaj a:");
		scanf_s("%d", &a);

		tab[i] = a;
	}

	for (int i = 0; i < rozmiar; i++)
	{
		if (i != 9) printf("%d, ", tab[i]);
		else printf("%d", tab[i]);
	}

    return 0;
}
