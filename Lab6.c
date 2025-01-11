#include <stdio.h>
#include <stdlib.h> //dynamiczna alokacja pamiêci
#include <math.h> //dla funkcji matematycznych np. sqrt
#include <time.h> //do losowania

void z1()
{
	int liczba1 = 15;
	int liczba2;

	printf("Podaj liczbe: ");
	scanf_s("%d", &liczba2);

	int* wsk1 = &liczba1;
	int* wsk2 = &liczba2;

	printf("Adres liczby zadeklarowanej: %p\n", wsk1);
	printf("Adres liczby pobranej: %p\n", wsk2);
	printf("Wartosc liczby pobranej: %d\n\n", *wsk2);

	int a, b, c, d, e;

	printf("Podaj a: ");
	scanf_s("%d", &a);
	printf("Podaj b: ");
	scanf_s("%d", &b);

	int* wsk_a = &a;
	int* wsk_b = &b;

	int roznica = *wsk_a - *wsk_b;
	printf("Roznica a - b: %d\n\n", roznica);

	printf("Podaj c: ");
	scanf_s("%d", &c);
	printf("Podaj d: ");
	scanf_s("%d", &d);
	printf("Podaj e: ");
	scanf_s("%d", &e);

	int* wsk_c = &c;
	int* wsk_d = &d;
	int* wsk_e = &e;

	float srednia = (float)(*wsk_c + *wsk_d + *wsk_e) / 3;
	printf("\nSrednia z liczb c, d, e: %f", srednia);
}

void z2()
{
	int tab[] = { 1,2,3,4 };
	int* ptr = tab;

	printf("Adres pierwszego elementu: %p\n", ptr);
	printf("Wartosc pierwszego elementu: %d\n", *ptr);
	printf("Adres czwartego elementu: %p\n", ptr + 3);
	printf("Wartosc czwartego elementu: %d\n\n", *(ptr + 3));

	//losowanie

	int n, i, min, max;

	int* wsk_n = &n, * wsk_i = &i, * wsk_min = &min, * wsk_max = &max;

	// Wczytanie rozmiaru tablicy
	printf("Podaj rozmiar tablicy: ");
	scanf_s("%d", wsk_n);

	if (*wsk_n <= 0) {
		printf("Rozmiar tablicy musi byc wiekszy od zera\n");
		return 0;
	}

	// Dynamiczna alokacja pamiêci
	int* tab1 = (int*)malloc((*wsk_n) * sizeof(int));
	if (tab1 == NULL) {
		printf("Nie udalo sie zaalokowac pamieci\n");
		return 0;
	}

	// Wszytywanie zakresu liczb
	printf("Podaj zakres minimalny liczb: ");
	scanf_s("%d", wsk_min);

	printf("Podaj zakres maksymalny liczb: ");
	scanf_s("%d", wsk_max);

	if (*wsk_min > *wsk_max) {
		printf("Wartoœæ minimalna musi byc mniejsza od maksymalnej\n");
		free(tab1);
		return 0;
	}

	// Wylosowanie liczb
	srand(time(NULL));

	// Wype³nienie tablicy liczbami losowymi z przedzia³u
	for (int i = 0; i < *wsk_n; i++) {
		tab1[i] = rand() % (*wsk_max - *wsk_min + 1) + *wsk_min;
	}

	// Wyœwietlenie wartoœci i adresów elementów tablicy
	printf("\nElementy tablicy i ich adresy:\n");
	for (*wsk_i = 0; *wsk_i < *wsk_n; (*wsk_i)++) {
		printf("tab1[%d] = %d, adres: %p\n", *wsk_i, tab1[*wsk_i], (void*)&tab1[*wsk_i]);
	}

	// Zwolnienie pamiêci
	free(tab1);
}

void z3()
{
	int n, i;
	int* wsk_n = &n, * wsk_i = &i;

	printf("Podaj liczbe elementow tablicy: ");
	scanf_s("%d", wsk_n);

	// Dynamiczna alokacja pamiêci na tablicê
	float* tablica = (float*)malloc((*wsk_n) * sizeof(float));
	if (tablica == NULL) {
		printf("Nie udalo sie zaalokowac pamieci\n");
		return 0;
	}

	// Wczytanie elementów do tablicy
	printf("\nPodaj %d elementow:\n", *wsk_n);
	for (*wsk_i = 0; *wsk_i < *wsk_n; i++) {
		printf("Element %d: ", *wsk_i + 1);
		scanf_s("%f", (tablica + *wsk_i)); // WskaŸnik do elementu
	}

	// Obliczenie œredniej
	float suma = 0, srednia;
	float* wsk_suma = &suma, * wsk_srednia = &srednia;

	for (*wsk_i = 0; *wsk_i < *wsk_n; (*wsk_i)++) {
		*wsk_suma += *(tablica + *wsk_i); // Pobieranie wartoœci przez wskaŸnik
	}

	*wsk_srednia = *wsk_suma / *wsk_n;
	printf("\nSrednia wartosc: %.2f\n", *wsk_srednia);

	// Wypisanie elementów wiêkszych od œredniej
	printf("\nElementy wieksze od sredniej:\n");
	for (*wsk_i = 0; *wsk_i < *wsk_n; (*wsk_i)++) {
		if (*(tablica + *wsk_i) > *wsk_srednia) {
			printf("%.2f\n", *(tablica + *wsk_i));
		}
	}

	// Zwolnienie pamiêci
	free(tablica);
}

int rowKw(double* a, double* b, double* c, double* x1, double* x2);

int rowKw(double* a, double* b, double* c, double* x1, double* x2) {
	double delta;
	double* wsk_delta = &delta;

	if (*a == 0) {
		printf("To nie jest rownanie kwadrotowe.\n");
		return -1; // b³¹d
	}

	*wsk_delta = ((*b) * (*b)) - (4 * (*a) * (*c));

	if (*wsk_delta > 0) {
		*x1 = (-(*b) + sqrt(*wsk_delta)) / (2 * (*a));
		*x2 = (-(*b) - sqrt(*wsk_delta)) / (2 * (*a));
		return 2; // zwrócenie informacji o dwóch rozwi¹zaniach
	}
	else if (*wsk_delta == 0)
	{
		*x1 = *x2 = -(*b) / (2 * (*a));
		return 1;// zwrócenie informacji o jednym rozwi¹zaniu
	}
	else return 0;
}

void z4()
{
	double a, b, c, x1, x2;
	double* wsk_a = &a, * wsk_b = &b, * wsk_c = &c, * wsk_x1 = &x1, * wsk_x2 = &x2;
	int* wynik = (int*)malloc(sizeof(int));

	printf("Podaj a: "); scanf_s("%lf", wsk_a);
	printf("Podaj b: "); scanf_s("%lf", wsk_b);
	printf("Podaj c: "); scanf_s("%lf", wsk_c);

	wynik = rowKw(wsk_a, wsk_b, wsk_c, wsk_x1, wsk_x2);

	if (wynik == 2) {
		printf("Dwa pierwiastki rzeczywiste: x1 = %.2f, x2 = %.2f.\n", *wsk_x1, *wsk_x2);
	}
	else if (wynik == 1) {
		printf("Jeden podwojny pierwiastek rzeczywisty: x1 = x2 = %.2f.\n", *wsk_x1);
	}
	else if (wynik == 0) {
		printf("Brak rozwiazania w zbiorze liczb rzeczywistych.\n");
	}
	else printf("Blad: a nie moze byc rowne zero.\n");

	return 0;
}

int* potega(int* n, int* wykl) {
	int* wynik = (int*)malloc(sizeof(int));  // Dynamiczna alokacja pamiêci
	*wynik = 1;

	for (int i = 0; i < *wykl; i++) {
		*wynik *= *n;  // Obliczanie potêgi
	}

	return wynik;  // Zwracanie wskaŸnika do wyniku
}

void z5()
{
	int n, wykl;
	int* wsk_n = &n, * wsk_wykl = &wykl;

	printf("Podaj liczbe: "); scanf_s("%d", wsk_n);
	printf("Podaj wykladnik: "); scanf_s("%d", wsk_wykl);

	// Przekazywanie wskaŸników
	int* wynik = potega(wsk_n, wsk_wykl);

	printf("%d do potegi %d wynosi %d\n", *wsk_n, *wsk_wykl, *wynik);

	free(wynik);  // Zwolnienie pamiêci
}

void powtorzZnak(char* znak, int* powt) {
	// Sprawdzamy, czy wskaŸniki nie s¹ NULL
	if (znak == NULL || powt == NULL) {
		printf("Nieprawidlowe dane\n");
		return;
	}

	int i;
	int* wsk_i = &i;

	// Wypisujemy znak podan¹ liczbê razy
	for (int wsk_i = 0; wsk_i < *powt; wsk_i++) {
		printf("%c", *znak);
	}
	printf("\n"); // Nowa linia po wypisaniu znaków

	// Zmniejszamy liczbê powtórzeñ o 1
	(*powt)--;
}

void z6()
{
	int powt;
	int* wsk_powt = &powt;
	char znak = '+';

	// Wczytywanie danych od u¿ytkownika

	printf("Podaj liczbe powtorzen: ");
	scanf_s("%d", wsk_powt);

	// Wywo³anie funkcji
	powtorzZnak(&znak, wsk_powt);
}


int minimalna(int* a, int* b, int** wsk_min) {
	if (*a < *b) {
		*wsk_min = a; // WskaŸnik do mniejszej wartoœci
		return *a;    // Mniejsza wartoœæ
	}
	else {
		*wsk_min = b;
		return *b;
	}
}

void z7()
{
	int x, y;
	int* wsk_x = &x, * wsk_y = &y;

	printf("Podaj x: ");
	scanf_s("%d", wsk_x);
	printf("Podaj y: ");
	scanf_s("%d", wsk_y);

	int* wsk_min; // WskaŸnik do przechowywania adresu mniejszej zmiennej

	// Wywo³anie funkcji
	int min = minimalna(wsk_x, wsk_y, &wsk_min);

	// Wyniki
	printf("Mniejsza wartosc: %d\n", min);
	printf("Adres zmiennej z mniejsza wartoscia: %p\n", (void*)wsk_min);
	printf("Wartosc pod wskazanym adresem: %d\n", *wsk_min);

	return 0;
}

void zamien(int* a, int* b) {
	int zam;
	int* wsk_zam = &zam;

	*wsk_zam = *a; // Przechowanie wartoœci pierwszej zmiennej
	*a = *b;       // Przypisanie wartoœci drugiej zmiennej do pierwszej
	*b = *wsk_zam;     // Przypisanie przechowanej wartoœci pierwszej zmiennej do drugiej
}

void z8()
{
	int x, y;
	int* wsk_x = &x, * wsk_y = &y;

	printf("Podaj x: ");
	scanf_s("%d", wsk_x);
	printf("Podaj y: ");
	scanf_s("%d", wsk_y);

	printf("\nPrzed zamiana: x = %d, y = %d\n", *wsk_x, *wsk_y);
	zamien(&*wsk_x, &*wsk_y);
	printf("Po zamianie: x = %d, y = %d\n", *wsk_x, *wsk_y);
}

int main()
{
	// zad 1
	z1();

	// zad 2
	z2();

	// zad 3
	z3();

	// zad 4
	z4();

	// zad 5
	z5();

	// zad 6
	z6();

	// zad 7
	z7();

	// zad 8
	z8();

	return 0;
}
