// main.c

#include <stdio.h>
#include <stdlib.h>
#include "beolvas.h"
#include "excelbeolvas.h"

void kiirKerdesek(Kerdesek *eleje) {
    Kerdesek *jelenlegi = eleje;

    while (jelenlegi != NULL) {
        printf("Nehezseg: %d\n", jelenlegi->nehezseg);
        printf("Kerdes: %s\n", jelenlegi->kerdes);
        printf("A: %s\n", jelenlegi->A);
        printf("B: %s\n", jelenlegi->B);
        printf("C: %s\n", jelenlegi->C);
        printf("D: %s\n", jelenlegi->D);
        printf("Valasz: %c\n", jelenlegi->valasz);
        printf("Kategoria: %s\n", jelenlegi->kategoria);

        jelenlegi = jelenlegi->kovetkezo;

        printf("\n");
    }
}

int main() {
    Kerdesek *eleje = NULL;
    const char *csvFajlnev = "C:\\Users\\Zephyrus\\Desktop\\kerdes.csv";

    beolvasCSV(csvFajlnev, &eleje);
    kiirKerdesek(eleje);
    felszabadit(eleje);

    return 0;
}
