#include <stdio.h>

int main()
{
	int a;
	printf("Podaj liczbe: ");
	scanf_s("%d", &a);

	if (a % 2 == 0) printf("Liczba parzysta\n");
	else printf("Liczba nieparzysta\n");

	return 0;
}

//Copyright MichalJanikUR®. Wszelkie prawa zastrzezone. All rights reserved.
