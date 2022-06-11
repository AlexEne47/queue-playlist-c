#include <stdio.h>
#include <stdlib.h>
#include "coada.h"

// Initializare coada playlist
queue InitQ() {
    queue aux = (queue)malloc(sizeof(struct coada));
    aux->head = aux->tail = NULL;
    return aux;
}

// Inserare piesa in playlist
void InsQ(queue *q, piesa t) {

    celula aux = (celula)malloc(sizeof(struct celula));
    aux->info = malloc(sizeof(piesa));
    *(piesa *)(aux->info) = t;
    aux->urm = NULL;

    if((*q)->head == NULL) {
        (*q)->head = (*q)->tail = aux;
    }
    else {
        (*q)->tail->urm = aux;
        (*q)->tail = (*q)->tail->urm;
    }
}

// Extragere piesa din playlist
piesa ExtrQ(queue *q) {

    if((*q)->head != NULL) {
    celula aux = (*q)->head;
    piesa t = *(piesa *)(aux->info);

    (*q)->head = (*q)->head->urm;
    free(aux->info);
    free(aux);

    return t;
    }
}

// Redam prima melodie din coada
void Play(queue q) {
    if(q->head == NULL) 
    printf("Lista de redare goala!\n");
    else {
        piesa aux = *(piesa *)(q->head->info);
        printf("Redam: %s - %s - %s - %s\n", aux.autor, aux.nume, aux.categorie, aux.durata);
        q->head = q->head->urm;
    }
}

// Redam toate melodiile secvential
void Play_all(queue q) {
    if(q->head == NULL) 
    printf("Lista de redare goala!\n");
    else {
        while(q->head != NULL) {
        piesa aux = *(piesa *)(q->head->info);
        printf("Redam: %s - %s - %s - %s\n", aux.autor, aux.nume, aux.categorie, aux.durata);
        q->head = q->head->urm;
        }
        printf("Am redat toate piesele!\n");
    }
}

// Eliberare memorie coada playlist
void FreeQ(queue *q) {

    if((*q)->head != NULL) {
    celula aux = (*q)->head;

    while(aux != NULL) {
        celula temp = aux;
        aux = aux ->urm;
        free(temp->info);
        free(temp);
    }
    }

    if((*q) != NULL)
    free((*q));
}

// Functie de afisare playlist
void Show(queue q) {
    int ID = 1;
    piesa aux;

    if(q->head == NULL) 
    printf("Lista de redare goala!\n");
    else {
        celula temp = q->head;

        while(temp != NULL) {
            aux = *(piesa *)temp->info;
            printf("%d) %s - %s - %s - %s\n", ID, aux.autor, aux.nume, aux.categorie, aux.durata);
            temp = temp->urm;
            ID++;
        }
    }
}