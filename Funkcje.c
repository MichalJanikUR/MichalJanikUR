#include <math.h>
#include <stdio.h>

// zad 1 - silnia z n
int silnia(int n)
{
	if (n == 0) return 1;
	return n * silnia(n - 1);
}

// zad 2 - n-ty wyraz ciagu
int wc(int n) {
	if (n == 1) return -1;
	else if (n > 1) return (-wc(n - 1) * n) - 2;
}

// zad 3 - nwd (algorytnem Euklidesa)
int nwd(int a, int b)
{
	if (b == 0) return a;
	return nwd(b, a % b);
}

// zad 6 - ci¹g Fibonacciego
int fib(int n)
{
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else if (n > 1) return fib(n - 2) + fib(n - 1);
}

// zad 5 (tak jak 7) - zamiana liczby dziesiêtnej na binarn¹
void dec2bin(int n) {
	if (n < 0) printf("Liczba musi byc wieksza lub rowna 0!");

	else
	{
		if (n > 1)
		{
			dec2bin(n / 2);
		}

		printf("%d", n % 2);
	}
}