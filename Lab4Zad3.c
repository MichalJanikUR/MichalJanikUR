#include <stdio.h>

int main()
{
	char tekst[50];

	printf("Podaj tekst: ");
	fgets(tekst, sizeof(tekst), stdin);

	int licz_samo = 0, licz_spol = 0, licz_spac = 0;

	for (int i = 0; tekst[i] != '\0'; i++)
	{
		if (tekst[i] == 'a' || tekst[i] == 'e' || tekst[i] == 'i' || tekst[i] == 'o' || tekst[i] == 'u' || tekst[i] == 'y' || tekst[i] == '�' || tekst[i] == '�' || tekst[i] == '�'
			|| tekst[i] == 'A' || tekst[i] == 'E' || tekst[i] == 'I' || tekst[i] == 'O' || tekst[i] == 'U' || tekst[i] == 'Y' || tekst[i] == '�' || tekst[i] == '�' || tekst[i] == '�') licz_samo++;
		else if (tekst[i] == ' ') licz_spac++;
		else licz_spol++;
	}

	printf("Liczba samoglosek: %d", licz_samo);
	printf("\nLiczba spolglosek: %d", licz_spol-1);

	return 0;
}