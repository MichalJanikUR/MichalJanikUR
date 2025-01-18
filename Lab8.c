#include <stdio.h>
#include <stdlib.h>

#define INPUT_FILE "promienie.txt"
#define OUTPUT_FILE "wynik.txt"

#define MAX_PESEL 1000
#define PESEL_LENGTH 11

// zadanie 1
double area(double radius) {
	return 3.14 * radius * radius;
}

int is_valid_pesel(const char* pesel) {
	int weights[] = { 1, 3, 7, 9, 1, 3, 7, 9, 1, 3 };
	int sum = 0;

	for (int i = 0; i < 10; i++) {
		int digit = pesel[i] - '0'; // Konwersja z char na int
		sum += digit * weights[i]; // Dodaj iloczyn cyfry i mnożnika
	}

	// Dodaj ostatnią cyfrę (kontrolną)
	int control_digit = pesel[10] - '0';
	sum += control_digit;

	// Poprawny PESEL: suma modulo 10 == 0
	return (sum % 10 == 0);
}

//zadanie 1

void RunZadanie1()
{
	FILE* inputFile, * outputFile;

	double radii[2], areas[2];

	//otwieranie pliku

	inputFile = fopen(INPUT_FILE, "r");
	if (inputFile == NULL) {
		printf("Nie moge otworzyc pliku %s.\n", INPUT_FILE);
		return 1; // exit(1);
	}

	//wczytanie danych z pliku do tablicy promieni
	for (int i = 0; i < 2; i++)
	{
		if (fscanf(inputFile, "%lf", &radii[i]) != 1) {
			printf("Blad odczytu danych z pliku %s\n", INPUT_FILE);
			fclose(inputFile);
			return 1;
		}
	}

	fclose(inputFile); //zamkniecie pliku promienie.txt

	//obliczanie pól

	for (int i = 0; i < 2; i++)
	{
		areas[i] = area(radii[i]);
	}

	//sortowanie rosnaco
	//[3,1]
	if (areas[0] > areas[1]) {
		double temp = areas[0];
		areas[0] = areas[1];
		areas[1] = temp;
	}

	//zapis wynikow do pliku
	outputFile = fopen(OUTPUT_FILE, "w");
	if (outputFile == NULL) {
		printf("Nie mozna otworzyc pliku %s do zapisywania wynikow\n", OUTPUT_FILE);
		return 1;
	}
	for (int i = 0; i < 2; i++)
	{
		fprintf(outputFile, "%.2lf\n", areas[i]);
	}
	fclose(outputFile);
	printf("Wyniki zapisano w pliku %s.\n", OUTPUT_FILE);
	return 0;
}

// zadanie 2

void RunZadanie2()
{
	FILE* inputFile = fopen("dane1.txt", "w");
	if (inputFile == NULL) {
		printf("Nie mozna utworzyc pliku dane1.txt");
		return 1;
	}

	// zapisanie liczb do pliku
	fprintf(inputFile, "25\n73\n40\n89\n18\n");
	fclose(inputFile);

	// otwieranie pliku w trybie odczytu
	inputFile = fopen("dane1.txt", "r");
	if (inputFile == NULL) {
		printf("Nie mozna otworzyc pliku dane1.txt");
		return 1;
	}

	// tworzenie nowego pliku do zapisu wyników
	FILE* outputFile = fopen("wynik1.txt", "w");
	if (outputFile == NULL) {
		printf("Nie mozna utworzyc pliku wynik1.txt");
		fclose(inputFile);
		return 1;
	}

	int number;
	while (fscanf(inputFile, "%d", &number) == 1) {
		int lastDigit = number % 10; // pobranie cyfry jedności
		if (lastDigit == 0 || lastDigit == 3 || lastDigit == 8 || lastDigit == 9) {
			fprintf(outputFile, "%d\n", number); // zapis liczby do wynik.txt
		}
	}

	// zamknięcie plików
	fclose(inputFile);
	fclose(outputFile);

	printf("Wyniki zapisano w pliku wynik1.txt.\n");
	return 0;
}

void RunZadanie3()
{

}

void RunZadanie4()
{
	FILE* input_file = fopen("dane.txt", "r");
	FILE* output_file = fopen("wyniki6.txt", "w");

	if (!input_file || !output_file) {
		printf("Nie mozna otworzyc pliku");
		return 1;
	}

	char pesel[MAX_PESEL][PESEL_LENGTH + 1];
	int count = 0;

	// Wczytaj numery PESEL z pliku
	while (count < MAX_PESEL && fgets(pesel[count], sizeof(pesel[count]), input_file)) {
		pesel[count][strcspn(pesel[count], "\n")] = '\0'; // Usuń znak nowej linii
		if (strlen(pesel[count]) != 11) {
			continue; // Pomijamy błędne numery
		}
		count++;
	}

	// 4.1: Liczba kobiet i mężczyzn
	int women_count = 0, men_count = 0;
	for (int i = 0; i < count; i++) {
		int gender_digit = pesel[i][9] - '0';
		if (gender_digit % 2 == 0) {
			women_count++;
		}
		else {
			men_count++;
		}
	}
	fprintf(output_file, "4.1\nKobiety: %d\nMezczyzni: %d\n\n", women_count, men_count);

	// 4.2: Liczba osób urodzonych w listopadzie
	int november_count = 0;
	for (int i = 0; i < count; i++) {
		int month = (pesel[i][2] - '0') * 10 + (pesel[i][3] - '0');
		if (month == 11 || month == 31) {
			november_count++;
		}
	}
	fprintf(output_file, "4.2\nUrodzeni w listopadzie: %d\n\n", november_count);

	// 4.3: Błędne numery PESEL
	fprintf(output_file, "4.3\nBledne numery PESEL:\n");
	for (int i = 0; i < count; i++) {
		if (!is_valid_pesel(pesel[i])) {
			fprintf(output_file, "%s\n", pesel[i]);
		}
	}

	fclose(input_file);
	fclose(output_file);

	printf("Wyniki zapisano w pliku wyniki6.txt\n");
}


int main(int argc, char* argv[])
{
	// zadanie 1
	//RunZadanie1();

	// zadanie 2
	//RunZadanie2();


	// zadanie 3

	if (argc != 3) {
		printf("Uzycie: %s <plik_wejsciowy> <plik_wyjsciowy>\n", argv[0]);
		return 1;
	}

	const char* input_file = argv[1];
	const char* output_file = argv[2];

	// Otwieranie pliku wejściowego
	FILE* input = fopen(input_file, "r");
	if (input == NULL) {
		printf("Nie mozna otworzyc pliku wejsciowego");
		return 1;
	}

	// Otwieranie pliku wyjściowego
	FILE* output = fopen(output_file, "w");
	if (output == NULL) {
		printf("Nie mozna otworzyc pliku wyjsciowego");
		fclose(input);
		return 1;
	}

	int char_count = 0;
	int ch;

	// Zliczanie znaków i kopiowanie zawartości
	while ((ch = fgetc(input)) != EOF) {
		char_count++;
	}

	// Dodanie liczby znaków na końcu pliku wyjściowego
	fprintf(output, "Liczba znakow w pliku: %d\n", char_count);

	// Zamknięcie plików
	fclose(input);
	fclose(output);

	printf("Wynik zapisano w pliku: %s\n", output_file);

	// zadanie 4

	//RunZadanie4();

	return 0;
	
}
