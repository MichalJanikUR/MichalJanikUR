#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main()
{
    int i, j, k;

    for (i = 10; i > 0; i--) {
		for (j = 0; j < i; j++)
			printf("X");
		printf("\n");
	}

	printf("\n");

    for (i = 10; i > 0; i--) {
		for (j = 0; j < i; j++)
			printf(" ");

		for (k = 0; k < 11-i; k++)
			printf("X");
		printf("\n");
	}

	printf("\n");

	for (i = 10; i > 0; i--) {
        for (k = 0; k < 11-i; k++)
			printf(" ");

        for (j = 0; j < i; j++)
			printf("X");
		printf("\n");
	}

	printf("\n");

	for (i = 10; i > 0; i--) {
		for (j = 0; j < i; j++)
			printf(" ");

		for (k = 0; k < 11-i; k++)
			printf("X");

		for (k = 0; k < 11-i; k++)
			printf("X");

		for (j = 0; j < i; j++)
			printf(" ");
        printf("\n");
	}

	return 0;
}
