#include <stdio.h>

typedef struct celula {
    void *info;
    struct celula *urm;
} *celula;

typedef struct coada {
    celula head;
    celula tail;
} *queue;

typedef struct piesa {
    char autor[30];
    char nume[30];
    char categorie[20];
    char durata[10];
} piesa;

queue InitQ();
void InsQ(queue *q, piesa t);
piesa ExtrQ(queue *q);
void Play(queue q); 
void Play_all(queue q);
void FreeQ(queue *q);
void Show(queue q);
