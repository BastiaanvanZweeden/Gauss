/* ---------------------------------------------------------------------------------------------------------------------------------------------------------------
   ------------------ Dieses Programm berechnet die Summe aller Natürlichen Zahlen bis zu einer vom Benutzer eingegebenen natürlichen Zahl -----------------------
   ------------------		von Bastiaan van Zweeden				Oktober 2020														   -----------------------
   ---------------------------------------------------------------------------------------------------------------------------------------------------------------
   */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

   // Die Funktionen werden deklariert
unsigned int bisZuWelcherNatuerlichenZahlSollSummiertWerden(void);
unsigned int welcherRechenwegSollGenommenWerden(void);
unsigned int gausscheBerechnung(unsigned int natuerlicheZahl);
unsigned int sequenzielleBerechnung(unsigned int natuerlicheZahl);
void ergebnissAusgabe(unsigned int ergebniss, unsigned int natuelicheZahl);

// Das Main Programm
int main(int argc, char** argv) {
	// die Variablen
	unsigned int natuerlicheZahl, ergebniss; 
	int rechenweg;

	natuerlicheZahl = bisZuWelcherNatuerlichenZahlSollSummiertWerden();
	rechenweg = welcherRechenwegSollGenommenWerden();
	
	if (rechenweg == 1) {
		ergebniss = sequenzielleBerechnung(natuerlicheZahl);
	}
	else {
		ergebniss = gausscheBerechnung(natuerlicheZahl);
	}
	ergebnissAusgabe(ergebniss, natuerlicheZahl);
}

// Die Funktionen
unsigned int bisZuWelcherNatuerlichenZahlSollSummiertWerden() {
	unsigned int natuerlicheZahl;
	do {
		printf("\nGeben Sie bitte an bis zu welcher Natuerlichen Zahl die Natuerlichen Zahlen Summiert werden sollen.\n");
		scanf("%u", &natuerlicheZahl);
	} while (natuerlicheZahl < 0);
	return natuerlicheZahl;
}

unsigned int welcherRechenwegSollGenommenWerden(void) {
	unsigned int auswahlRechenweg;
	do {
		printf("\nWelchen Rechenweg möchten Sie um die Summe zu blilden?\n");
		printf("(1) Alle Zahlen werden einzeln aufaddiert.\n");
		printf("(2) Die Summe wird mit der Gauschen Summenformel gebildet.\n");
		printf("Geben Sie bitte Ihre Auswahl an:\t");
		scanf("%u", &auswahlRechenweg);
	} while (auswahlRechenweg > 2);
	return auswahlRechenweg;
}

unsigned int gausscheBerechnung(unsigned int natuerlicheZahl) {
	unsigned int summe;
	summe = (natuerlicheZahl * natuerlicheZahl + natuerlicheZahl) / 2;
	return summe;
}

unsigned int sequenzielleBerechnung(unsigned int natuerlicheZahl) {
	unsigned int i, summe=0;
	for (i = 1; i <= natuerlicheZahl; i++) {
		summe = summe + i;
	}
	return summe;
}

void ergebnissAusgabe(unsigned int ergebniss, unsigned int natuelicheZahl){
	printf("\nDie Summe aller natuerlichen Zahlen bis %u ist %u .\n\n", natuelicheZahl, ergebniss);
}
