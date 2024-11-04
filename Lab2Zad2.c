#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	int liczba, licznik = 0, suma = 0;
	for (int i = 0; i < 10; i++)
	{
		printf("Podaj %d liczbe: ", i + 1);
		scanf_s("%d", &liczba);

		licznik++;
		suma += liczba;
	}

	printf("Suma %d liczb: %d", licznik, suma);

	return 0;
}