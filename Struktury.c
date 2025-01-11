#include "Struktury.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//zadanie 1

float obwodTrojkata(Trojkat t1) {
	float obwod = t1.a + t1.b + t1.c;
	return obwod;
}

//zadanie 2

void przepiszTrojkat(Trojkat troj1, Trojkat* troj2) {
    troj2->a = troj1.a;
    troj2->b = troj1.b;
    troj2->c = troj1.c;
}

// zadanie 3

double odleglosc(Punkt p1, Punkt p2) {
    // Obliczanie odleg³oœci miêdzy dwoma punktami w trójwymiarze
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
        (p1.y - p2.y) * (p1.y - p2.y) +
        (p1.z - p2.z) * (p1.z - p2.z));
}

double najmniejszaOdleglosc(Punkt tab[], int rozmiar) {
    double min_odleglosc = odleglosc(tab[0], tab[1]);

    // Sprawdzanie odleg³oœci pomiêdzy wszystkimi parami punktów tablicy
    for (int i = 0; i < rozmiar - 1; i++) {
        for (int j = i + 1; j < rozmiar; j++) {
            double odleglosc_punktu = odleglosc(tab[i], tab[j]);
            if (odleglosc_punktu < min_odleglosc) {
                min_odleglosc = odleglosc_punktu;
            }
        }
    }

    return min_odleglosc;
}

// zadanie 4
void przepiszTablice(Punkt tab1[], Punkt tab2[], int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        tab2[i] = tab1[i];
    }
}

//zadanie 6

void przepiszTablice10(Punkt10 tab1[], Punkt10 tab2[], int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        memcpy(tab2[i].wspolrzedne, tab1[i].wspolrzedne, sizeof(tab1[i].wspolrzedne));
    }
}

// zadanie 7

void kopiujPunkty(Punktn* tab1, Punktn* tab2, int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        tab2[i].wspolrzedne = (double*)malloc(tab1[i].liczba_wymiarow * sizeof(double));

        if (tab2[i].wspolrzedne == NULL) {
            printf("B³¹d przydzielania pamiêci!\n");
            return 0;
        }

        tab2[i].liczba_wymiarow = tab1[i].liczba_wymiarow;

        for (int j = 0; j < tab1[i].liczba_wymiarow; j++) {
            tab2[i].wspolrzedne[j] = tab1[i].wspolrzedne[j];
        }
    }
}

void zwolnijPamiec(Punktn* tablica, int rozmiar) {
    for (int i = 0; i < rozmiar; i++) {
        free(tablica[i].wspolrzedne);
    }
}

// zadanie 8

Zespolone dodaj(Zespolone a, Zespolone b) {
    Zespolone wynik;
    wynik.re = a.re + b.re;
    wynik.im = a.im + b.im;
    return wynik;
}

// zadanie 9

double pole(Figura f) {
    switch (f.typ) {
    case 1:
        return 0.5 * f.wymiary.trojkat.podstawa * f.wymiary.trojkat.wysokosc;
    case 2:
        return f.wymiary.prostokat.dlugosc * f.wymiary.prostokat.szerokosc;
    case 3:
        return f.wymiary.rownoleglobok.podstawa * f.wymiary.rownoleglobok.wysokosc;
    case 4:
        return 0.5 * (f.wymiary.trapez.podstawa1 + f.wymiary.trapez.podstawa2) * f.wymiary.trapez.wysokosc;
    default:
        printf("Bledne dane\n");
        break;
    }
}