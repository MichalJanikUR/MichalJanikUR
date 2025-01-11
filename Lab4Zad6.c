#include <stdio.h>
#include <string.h>

void transform(const char* we, char* wy) {
    const char* s1 = "abcdefghijklmnopqrstuvwxyz";
    const char* s2 = "zyxwvutsrqponmlkjihgfedcba";

    while (*we) {
        char* poz = strchr(s1, *we); // Sprawdzenie przynależnosci znaku do s1
        if (poz) {
            wy[0] = s2[poz - s1]; // Zamiana na odpowiednik z s2
        }
        else {
            poz = strchr(s2, *wy); // Sprawdzenie przynależnosci znaku do s2
            if (poz) {
                wy[0] = s1[poz - s2]; // Zamiana na odpowiednik z s1
            }
            else {
                wy[0] = *we; // Zostawienie znaku bez zmian
            }
        }
        we++; //Przejście do kolejnych znaków
        wy++;
    }
    wy[0] = '\0'; // Zakończenie ciągu znaków sekwencją '\0'
}

int main() {
    char we[100], wy[100]; //Tablica znaków wejścia i wyjścia

    printf("Podaj ciag znakow: ");
    fgets(we, sizeof(we), stdin); // Pobiera ciąg znaków z białymi znakami (np. spacje)
    we[strcspn(we, "\n")] = '\0'; // Usuwa znak nowej linii

    transform(we, wy);

    printf("Nowy ciag po transformacji: %s\n", wy);

    return 0;
}
