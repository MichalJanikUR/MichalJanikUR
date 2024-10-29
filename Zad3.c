#include <stdio.h>

int main()
{
	float a, b;

	printf("Podaj liczbe a:");
	scanf_s("%f", &a);
	printf("Podaj liczbe b:");
	scanf_s("%f", &b);

	if(a > b) printf("Liczba a jest wieksza od b!\n");
	else if(a == b) printf("Liczby a i b sa sobie rowne!\n");
	else printf("Liczba b jest wieksza od a!\n");

	return 0;
}

//Copyright MichalJanikUR®. Wszelkie prawa zastrzezone. All rights reserved.
