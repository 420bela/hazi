#ifndef BEOLVAS_H_INCLUDED
#define BEOLVAS_H_INCLUDED
#include <stdio.h>

typedef struct Kerdesek {
    int nehezseg;
    char kerdes[100];
    char A[20];
    char B[20];
    char C[20];
    char D[20];
    char valasz;
    char kategoria[10];
    struct Kerdesek *kovetkezo;

} Kerdesek;

Kerdesek *uj(int nehezseg,char *kerdes,char*A, char*B,char*C,char*D,char valasz, char*kategoria);

void hozzafuz(Kerdesek*eleje, Kerdesek* uj);

void felszabadit(Kerdesek*eleje);

#endif // BEOLVAS_H_INCLUDED
