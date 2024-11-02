#include <stdio.h>

int main()
{
	float liczba, srednia, suma = 0;
	int licznik = 0;

	for (int i = 1; i <= 4; i++)
	{
		printf("Podaj %d liczbe:", i);
		scanf_s("%f", &liczba);

		suma += liczba;
		licznik++;
	}

	srednia = suma / licznik;

	printf("Srednia %d wprowadzonych liczb wynosi: %f\n", licznik, suma);

	return 0;
}

//Copyright MichalJanikURŽ. Wszelkie prawa zastrzezone. All rights reserved.
