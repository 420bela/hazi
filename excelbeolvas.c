// excelbeolvas.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "excelbeolvas.h"

void beolvasCSV(const char *fajlnev, Kerdesek **eleje) {
    FILE *fajl = fopen(fajlnev, "r");
    if (!fajl) {
        printf("Hiba: Nem siker�lt megnyitni a f�jlt.\n");
        return;
    }

    // Kihagyjuk a fejl�c sort
    if (fscanf(fajl, "%*[^\n]\n") == EOF) {
        printf("Hiba: Nem siker�lt beolvasni az els� sort.\n");
        fclose(fajl);
        return;
    }

    Kerdesek *utolso = NULL;  // Az utols� elemre mutat� pointer
    while (fscanf(fajl, "%d,%99[^,],%19[^,],%19[^,],%19[^,],%19[^,],%c,%9[^,\n]\n",
                  &(utolso->nehezseg), utolso->kerdes, utolso->A, utolso->B, utolso->C, utolso->D, &(utolso->valasz), utolso->kategoria) == 8) {
        Kerdesek *uj_kerdes = uj(utolso->nehezseg, utolso->kerdes, utolso->A, utolso->B, utolso->C, utolso->D, utolso->valasz, utolso->kategoria);
        hozzafuz(*eleje, uj_kerdes);
        utolso = uj_kerdes;  // Friss�tj�k az utols� elemre mutat� pointert
    }

    fclose(fajl);
}
