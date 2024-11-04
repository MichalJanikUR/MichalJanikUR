#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	int n, i;
	float pkt, suma = 0, srednia;

	printf("Podaj liczbe studentow:");
	scanf_s("%d", &n);

	while (i <= n)
	{
		printf("Wprowadz liczbe punktow dla %d studenta:", i);
		scanf_s("%d", &pkt);

		suma += pkt;

		i++;
	}

	srednia = suma / (i-1);

	printf("\nSrednia: %f", srednia);

	return 0;
}