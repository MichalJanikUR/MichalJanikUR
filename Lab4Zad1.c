#include <stdio.h>
#include <string.h>

int main()
{
	char tekst1[50] = "Jan ";
	char tekst2[50] = "Kowalski";

	char tekst3[50];
	strcpy_s(tekst3, sizeof(tekst3), tekst1);

	printf("Skopiowany tekst: %s\n", tekst3);

	strcat_s(tekst1, sizeof(tekst3), tekst2);

	printf("Imie i nazwisko: %s\n", tekst1);

	int porownaj = strcmp(tekst1, tekst2);
	if (porownaj == 0) printf("Napisy sa rowne\n");
	else if (porownaj < 0) printf("Napis pierwszy jest mniejszy leksykograficznie\n");
	else printf("Napis pierwszy jest wiekszy leksykograficznie\n");

	int dlugosc = strlen(tekst3);
	printf("Dlugosc skopiowanego tekstu (tekst1 -> tekst3) : %d", dlugosc);
}