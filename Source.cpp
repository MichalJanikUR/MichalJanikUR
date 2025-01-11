#include <stdio.h>
#include "Funkcje.h"

int main() {

	// zad 1 - silnia z n

	printf("silnia(1) = %d", silnia(1));

	printf("\n\n");

	printf("silnia(4) = %d",silnia(4));

	printf("\n\n");

	//zad 2 - n-ty wyraz ciagu

	printf("wyraz ciagu dla 5: %d", wc(5));

	printf("\n\n");

	// zad 3 - nwd(algorytnem Euklidesa)

	printf("nwd(75, 100): %d", nwd(75, 100));

	printf("\n\n");

	// zad 6 - ci¹g Fibonacciego

	printf("fib(0): %d", fib(0));

	printf("\n\n");

	printf("fib(1): %d", fib(1));

	printf("\n\n");

	printf("fib(14): %d", fib(14));

	printf("\n\n");

	// zad 5 (tak jak 7) - zamiana liczby dziesiêtnej na binarn¹

	printf("-5 na bin: ");
	dec2bin(-5);

	printf("\n\n");

	printf("13 na bin: ");
	dec2bin(13);

	printf("\n");

	return 0;
}
