#include <stdio.h>
#include <stdlib.h>
#include "Struktury.h"
#include "Zadania.h"

void runMain() {
    int zadanie;
    printf("========= Zadania Lab 16.12.2024 ============\n");
    printf("1. Zadanie 1\n");
    printf("2. Zadanie 2\n");
    printf("3. Zadanie 3\n");
    printf("4. Zadanie 4\n");
    printf("5. Zadanie 5\n");
    printf("6. Zadanie 6\n");
    printf("7. Zadanie 7\n");
    printf("8. Zadanie 8\n");
    printf("9. Zadanie 9\n");
    printf("0. Wyjscie\n");
    printf("Wybierz zadanie: \n");
    scanf_s("%d", &zadanie);

    switch (zadanie)
    {
    case 1: runZadanie1(); break;
    case 2: runZadanie2(); break;
    case 3: runZadanie3(); break;
    case 4: runZadanie4(); break;
    case 5: runZadanie5(); break;
    case 6: runZadanie6(); break;
    case 7: runZadanie7(); break;
    case 8: runZadanie8(); break;
    case 9: runZadanie9(); break;
    case 0: break;

    default:
        printf("Bledne dane\n");
        break;
    }
}


void runZadanie1() {
    Trojkat t1;
    printf("\nPodaj bok a: "); scanf_s("%f", &t1.a);
    printf("Podaj bok b: "); scanf_s("%f", &t1.b);
    printf("Podaj bok c: "); scanf_s("%f", &t1.c);

    printf("\nObwod trojkata: %.2f", obwodTrojkata(t1));
}

void runZadanie2() {
    Trojkat troj1, troj2;

    printf("\nPodaj bok a: "); scanf_s("%f", &troj1.a);
    printf("Podaj bok b: "); scanf_s("%f", &troj1.b);
    printf("Podaj bok c: "); scanf_s("%f", &troj1.c);

    przepiszTrojkat(troj1, &troj2);

    printf("\nPrzepisane zmienne dla Trojkat t2:\n a: %.2f, b: %.2f, c: %.2f.\n", troj2.a, troj2.b, troj2.c);
}

void runZadanie3() {
    Punkt tab[] = {
        {3.0, 5.0, 8.0},
        {9.0, 3.0, 2.0},
        {2.0, 1.0, 7.0},
        {6.0, 7.0, 1.0}
    };

    int rozmiar = sizeof(tab) / sizeof(tab[0]);

    double min_odleglosc = najmniejszaOdleglosc(tab, rozmiar);

    printf("\nNajmniejsza odleglosc: %.2f\n", min_odleglosc);
}

void runZadanie4() {
    Punkt tab1[] = {
        {7.0, 1.0, 9.0},
        {9.0, 6.0, 1.0},
        {0.0, 3.0, 9.0},
        {1.0, 2.0, 1.0}
    };

    int rozmiar = sizeof(tab1) / sizeof(tab1[0]);

    Punkt *tab2 = (Punkt *)malloc(rozmiar * sizeof(Punkt));

    przepiszTablice(tab1, tab2, rozmiar);

    printf("\nZawartosc tablicy tab2:\n");
    for (int i = 0; i < rozmiar; i++) {
        printf("Punkt %d: (%.2f, %.2f, %.2f)\n", i + 1, tab2[i].x, tab2[i].y, tab2[i].z);
    }
}

void runZadanie5() {
    Struktura tablica_statyczna[10];

    Struktura* tablica_dynamiczna = (Struktura*)malloc(10 * sizeof(Struktura));
    if (tablica_dynamiczna == NULL) {
        printf("Nie udalo sie zaalokowac pamieci.\n");
        return 0;
    }

    Struktura* tablica_wskaznikow[10];

    int suma_statyczna = 0, suma_dynamiczna = 0, suma_wskaznikow = 0;

    for (int i = 0; i < 10; i++) {
        tablica_statyczna[i].liczba = i + 1;
        snprintf(tablica_statyczna[i].napis, sizeof(tablica_statyczna[i].napis), "Napis %d", i + 1);
        suma_statyczna += tablica_statyczna[i].liczba;
    }

    for (int i = 0; i < 10; i++) {
        tablica_dynamiczna[i].liczba = i + 11;
        snprintf(tablica_dynamiczna[i].napis, sizeof(tablica_dynamiczna[i].napis), "Napis %d", i + 11);
        suma_dynamiczna += tablica_dynamiczna[i].liczba;
    }

    for (int i = 0; i < 10; i++) {
        tablica_wskaznikow[i] = (Struktura*)malloc(sizeof(Struktura));
        if (tablica_wskaznikow[i] == NULL) {
            printf("Nie udalo sie zaalokowac pamieci dla wskaŸnika %d.\n", i);
            return 0;
        }
        tablica_wskaznikow[i]->liczba = i + 21;
        snprintf(tablica_wskaznikow[i]->napis, sizeof(tablica_wskaznikow[i]->napis), "Napis %d", i + 21);
        suma_wskaznikow += tablica_wskaznikow[i]->liczba;
    }

    printf("\nSuma pol liczbowych w tablicy statycznej: %d\n", suma_statyczna);
    printf("Suma pol liczbowych w tablicy dynamicznej: %d\n", suma_dynamiczna);
    printf("Suma pol liczbowych w tablicy wskaznikow: %d\n", suma_wskaznikow);

    free(tablica_dynamiczna);
    for (int i = 0; i < 10; i++) {
        free(tablica_wskaznikow[i]);
    }
}

void runZadanie6() {
    Punkt10 tab1[3] = {
        {{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0}},
        {{11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0, 20.0}},
        {{21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0, 30.0}}
    };

    Punkt10 tab2[3];

    przepiszTablice10(tab1, tab2, 3);

    printf("\nTablica tab2 po skopiowaniu:\n");
    for (int i = 0; i < 3; i++) {
        printf("Punkt %d: ", i + 1);
        for (int j = 0; j < 10; j++) {
            printf("%.1f ", tab2[i].wspolrzedne[j]);
        }
        printf("\n");
    }
}

void runZadanie7() {
    int rozmiar = 3;

    Punktn* tab1 = (Punktn*)malloc(rozmiar * sizeof(Punktn));
    Punktn* tab2 = (Punktn*)malloc(rozmiar * sizeof(Punktn));

    if (tab1 == NULL || tab2 == NULL) {
        printf("Blad przydzielania pamieci dla tablic punktow\n");
        return 0;
    }

    for (int i = 0; i < rozmiar; i++) {
        tab1[i].liczba_wymiarow = 3; //przyk³adowo 3 wymiary
        tab1[i].wspolrzedne = (double*)malloc(tab1[i].liczba_wymiarow * sizeof(double));
        if (tab1[i].wspolrzedne == NULL) {
            printf("Blad przydzielania pamieci dla wspolrzednych punktu %d\n", i);
            return 0;
        }        
        for (int j = 0; j < tab1[i].liczba_wymiarow; j++) {
            tab1[i].wspolrzedne[j] = i * 10 + j;  // przyk³adowe dane
        }
    }

    kopiujPunkty(tab1, tab2, rozmiar);

    printf("\n");

    for (int i = 0; i < rozmiar; i++) {
        printf("Punkt %d: ", i + 1);
        for (int j = 0; j < tab2[i].liczba_wymiarow; j++) {
            printf("%f ", tab2[i].wspolrzedne[j]);
        }
        printf("\n");
    }

    zwolnijPamiec(tab1, rozmiar);
    zwolnijPamiec(tab2, rozmiar);
    free(tab1);
    free(tab2);
}

void runZadanie8() {
    Zespolone z1 = { 3.0, 4.0 };
    Zespolone z2 = { 1.0, 2.0 };

    Zespolone suma = dodaj(z1, z2);

    printf("\nSuma: %.2f + %.2fi\n", suma.re, suma.im);
}

void runZadanie9() {
    Figura trojkat = { 1, .wymiary.trojkat = {5.0, 10.0} };
    Figura prostokat = { 2, .wymiary.prostokat = {4.0, 8.0} };
    Figura rownoleglobok = { 3, .wymiary.rownoleglobok = {6.0, 7.0} };
    Figura trapez = { 4, .wymiary.trapez = {3.0, 5.0, 4.0} };

    printf("\nPole trojkata: %.2f\n", pole(trojkat));
    printf("Pole prostokata: %.2f\n", pole(prostokat));
    printf("Pole rownolegloboku: %.2f\n", pole(rownoleglobok));
    printf("Pole trapezu: %.2f\n", pole(trapez));
}