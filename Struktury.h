#pragma once
// zadanie 1
typedef struct {
	float a, b, c;
} Trojkat;

float obwodTrojkata(Trojkat t1);

//zadanie 2

void przepiszTrojkat(Trojkat troj1, Trojkat* troj2);

// zadanie 3

typedef struct {
	double x, y, z;
} Punkt;

double odleglosc(Punkt p1, Punkt p2);

double najmniejszaOdleglosc(Punkt tab[], int rozmiar);

// zadanie 4

void przepiszTablice(Punkt tab1[], Punkt tab2[], int rozmiar);

// zadanie 5

typedef struct {
	int liczba;
	char napis[50];
} Struktura;

// zadanie 6

typedef struct {
	float wspolrzedne[10];
} Punkt10;

void przepiszTablice10(Punkt10 tab1[], Punkt10 tab2[], int rozmiar);

// zadanie 7

typedef struct {
	double* wspolrzedne;
	int liczba_wymiarow;
} Punktn;

void kopiujPunkty(Punktn* tab1, Punktn* tab2, int rozmiar);
void zwolnijPamiec(Punktn* tablica, int rozmiar);

// zadanie 8

typedef struct {
	double re;
	double im;
} Zespolone;

Zespolone dodaj(Zespolone a, Zespolone b);

//zadanie 9

typedef struct {
	int typ; // 1 - trójk¹t, 2 - prostok¹t, 3 - równoleg³obok, 4 - trapez
	union {
		struct { double podstawa, wysokosc; } trojkat;
		struct { double dlugosc, szerokosc; } prostokat;
		struct { double podstawa, wysokosc; } rownoleglobok;
		struct { double podstawa1, podstawa2, wysokosc; } trapez;
	} wymiary;
}Figura;

double pole(Figura f);