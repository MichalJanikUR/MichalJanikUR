#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	int n, liczba, suma = 0;

	printf("Podaj ilosc cyfr ciagu n:");
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++)
	{
		printf("Podaj %d liczbe:", i + 1);
		scanf_s("%d", &liczba);

		if (liczba % 2 == 0) suma += liczba;
	}

	printf("Suma liczb parzystych: %d", suma);

	return 0;
}

