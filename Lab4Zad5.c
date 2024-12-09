#include <stdio.h>

int main()
{
	char liczba[50];

	printf("Wczytaj liczbe calkowita: ");
	fgets(liczba, sizeof(liczba), stdin);

	for (int i = 0; liczba[i] != '\0'; i++)
	{
		if (liczba[i] == '0') printf("zero ");
		else if (liczba[i] == '1') printf("jeden ");
		else if (liczba[i] == '2') printf("dwa ");
		else if (liczba[i] == '3') printf("trzy ");
		else if (liczba[i] == '4') printf("cztery ");
		else if (liczba[i] == '5') printf("piec ");
		else if (liczba[i] == '6') printf("szesc ");
		else if (liczba[i] == '7') printf("siedem ");
		else if (liczba[i] == '8') printf("osiem ");
		else if (liczba[i] == '9') printf("dziewiec ");
	}

	printf("\n");

	return 0;
}