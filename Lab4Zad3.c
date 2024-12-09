#include <stdio.h>

int main()
{
	char tekst[50];

	printf("Podaj tekst: ");
	fgets(tekst, sizeof(tekst), stdin);

	int licznik_sm = 0, licznik_sp=0;

	for (int i = 0; tekst[i] != '\0'; i++)
	{
		if (tekst[i] == 'a' || tekst[i] == 'e' || tekst[i] == 'i' || tekst[i] == 'o' || tekst[i] == 'u' || tekst[i] == 'y' || tekst[i] == '¹' || tekst[i] == 'ê' || tekst[i] == 'ó'
			|| tekst[i] == 'A' || tekst[i] == 'E' || tekst[i] == 'I' || tekst[i] == 'O' || tekst[i] == 'U' || tekst[i] == 'Y' || tekst[i] == '¥' || tekst[i] == 'Ê' || tekst[i] == 'Ó') licznik_sm++;
		else if (tekst[i] != ' ') licznik_sp++;
	}

	printf("Liczba samoglosek: %d", licznik_sm);
	printf("\nLiczba spolglosek: %d\n", licznik_sp);

	return 0;
}