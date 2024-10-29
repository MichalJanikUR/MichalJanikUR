#include <stdio.h>

int main()
{
	int znak, uruchomiony = 1;

	float a, b, suma, roznica, iloczyn, iloraz;

	printf("Podaj 1 liczbe:");
	scanf_s("%f", &a);
	printf("Podaj 2 liczbe:");
	scanf_s("%f", &b);

	printf("\n----------------------\nWybierz jedna z opcji:\n\n1 - Dodawanie\n2 - Odejmowanie\n3 - Mnozenie\n4 - Dzielenie \nPozostale - Wyjscie\n----------------------\n");

	do
	{
		printf("\nWybierz dowolna opcje z menu: ");
		scanf_s("%d", &znak);

		switch (znak)
		{
		case 1:
			suma = a + b;

			printf("\nSuma %f i %f wynosi %f\n", a, b, suma);
			break;
		case 2:
			roznica = a - b;

			printf("\nRoznica %f i %f wynosi %f\n", a, b, roznica);
			break;
		case 3:
			iloczyn = a * b;

			printf("\nIloczyn %f i %f wynosi %f\n", a, b, iloczyn);
			break;
		case 4:
			if (b != 0)
			{
				iloraz = a / b;
				printf("\nIloraz %f i %f wynosi %f\n", a, b, iloraz);
			}
			else
			{
				printf("\nMianownik b wynosi 0 - nie mozna dzielic przez 0!\n");
				return 0;
			}

			break;
		default:
			printf("\nNie wybrano zadnej funkcji!\n");
			uruchomiony = 0;
			break;
		};
	}
	while (uruchomiony);

	return 0;
}

//Copyright MichalJanikUR®. Wszelkie prawa zastrzezone. All rights reserved.
