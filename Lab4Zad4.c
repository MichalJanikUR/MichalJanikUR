#include <stdio.h>

int main()
{
	char tekst[50];

	printf("Podaj tekst: ");
	fgets(tekst, sizeof(tekst), stdin);

	for (int i = 0; tekst[i] != '\0'; i++)
	{
		if (tekst[i]>='a' && tekst[i]<='z') tekst[i] = tekst[i] - 32;
	}

	printf("Tekst po przemianie: %s\n", tekst);

	return 0;
}