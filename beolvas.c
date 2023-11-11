#include "beolvas.h"
#include <stdio.h>

Kerdesek *uj(int nehezseg,char *kerdes,char*A, char*B,char*C,char*D,char valasz, char*kategoria) {
    Kerdesek *ujelem =(Kerdesek *)malloc(sizeof(Kerdesek));

    sprintf(ujelem->kerdes,"%s",kerdes);
    sprintf(ujelem->A,"%s",A);
    sprintf(ujelem->B,"%s",B);
    sprintf(ujelem->C,"%s",C);
    sprintf(ujelem->D,"%s",D);
    sprintf(ujelem->kategoria,"%s",kategoria);
    ujelem->valasz=valasz;
    ujelem->nehezseg=nehezseg;
    ujelem->kovetkezo=NULL;
    return ujelem;
}

void hozzafuz(Kerdesek*eleje, Kerdesek* uj){
    Kerdesek *jelenlegi=eleje;
    while(jelenlegi->kovetkezo!=NULL){
        jelenlegi=jelenlegi->kovetkezo;
    }
    jelenlegi->kovetkezo=uj;

}

void felszabadit(Kerdesek *eleje){
    Kerdesek *jelenlegi=eleje;
    Kerdesek *kovetkezo=eleje->kovetkezo;
    while(jelenlegi!=NULL){
        free(jelenlegi);
        jelenlegi=kovetkezo;
        if(kovetkezo!=NULL){
            kovetkezo=kovetkezo->kovetkezo;
        }
    }

}
