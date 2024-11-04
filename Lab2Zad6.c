#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
	for (int i = 1; i <= 100; i++)
	{
		if (i != 100) printf("%d, ", i);
		else printf("%d", i);
	}

	printf("\n\n");

	for (int i = 100; i >= 0; i--)
	{
		if (i != 0) printf("%d, ", i);
		else printf("%d", i);
	}

	printf("\n\n");

	for (int i = 7; i <= 77; i += 7)
	{
		if (i != 77) printf("%d, ", i);
		else printf("%d", i);
	}

	printf("\n\n");

	for (int i = 20; i >= 0; i -= 2)
	{
		if (i != 0) printf("%d, ", i);
		else printf("%d", i);
	}

	printf("\n\n");

	return 0;
}