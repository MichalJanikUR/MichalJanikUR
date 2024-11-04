#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <time.h>
#include <Windows.h>

int main()
{
	int n, liczba, suma = 0;

	srand(time(NULL));

	printf("Podaj ilosc cyfr ciagu n:");
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++)
	{
		liczba = rand() % 56 - 10;
		printf("Wylosowana %d liczba:", i + 1);
		printf("%d\n", liczba);

		if (liczba % 2 == 0) suma += liczba;
	}

	printf("Suma liczb parzystych: %d", suma);

	return 0;
}