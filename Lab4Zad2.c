#include <stdio.h>

int main()
{
	char c[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	size_t dlugosc1 = sizeof(c) / sizeof(c[0]);

	for (int i = 0; i < dlugosc1; i++)
	{
		printf("%c ", c[i]);
	}

	printf("\n\n");

	for (int i = 0; i < dlugosc1; i++)
	{
		printf("%d ", c[i]);
	}

	printf("\n\n");

	char C[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

	for (int i = 0; i < dlugosc1; i++)
	{
		printf("%c ", C[i]);
	}

	printf("\n\n");

	for (int i = 0; i < dlugosc1; i++)
	{
		printf("%d ", C[i]);
	}

	printf("\n\n");

	char l[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	size_t dlugosc2 = sizeof(l) / sizeof(l[0]);

	for (int i = 0; i < dlugosc2; i++)
	{
		printf("%c ", l[i]);
	}

	printf("\n\n");

	for (int i = 0; i <= 9; i++)
	{
		printf("%d ", l[i]);
	}

	printf("\n");

	return 0;
}