#include <stdio.h>

int main()
{
    int tab[10], liczba, rozmiar = sizeof(tab) / sizeof(tab[0]), min;

	srand(time(NULL));

	for (int i = 1; i < rozmiar; i++)
	{
	    //wzór: min + rand() % (max - min + 1)
		liczba = -23 + rand() % 74;
		printf("%d, ", liczba);

		tab[i] = liczba;

        if(i == 1) min = tab[i];
        else{
            if(min > tab[i]) min = tab[i];
        }
	}

	printf(" Min: %d", min);

    return 0;
}


