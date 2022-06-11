#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "coada.h"

int main(int argc, char *argv[]) {

    char line[150], *p;

    queue playlist = InitQ();
    printf("Comenzi acceptate: add <cd_file_name>, show, play, play all, exit\n");

    while(1) {
    fgets(line,sizeof(line),stdin);
    line[strlen(line) - 1] = '\0';

    p = strtok(line, " ");

    if(strcmp(p, "add") == 0) {
        p = strtok(NULL, " ");
        FILE *cd = fopen(p,"r");

        if(cd == NULL) 
        printf("Nu exista cd-ul \n");
        else {
    
        // Citim din fisier piesa cu piesa
        while(fgets(line,sizeof(line), cd)) {

        // Aloc spatiu pentru o piesa noua
        piesa melodie;

        // Scoatem newline adaugat de fgets
        if(line[strlen(line) - 1] == '\n')
        line[strlen(line) - 1] = '\0';

        // Autor
        p = strtok(line, "-");
        strcpy(melodie.autor, p);

        // Nume
        p = strtok(NULL, "-");
        strcpy(melodie.nume, p);

        // Categorie
        p = strtok(NULL, "-");
        strcpy(melodie.categorie, p);

        // Durata
        p = strtok(NULL, "-");
        strcpy(melodie.durata, p);

        // Adaug piesa in lista de redare
        InsQ(&playlist, melodie);
        }
        }
    }
    else if(strcmp(p, "play") == 0) {
    p = strtok(NULL, " ");

    // Redam o piesa sau toate secvential
    if(p == NULL)
    Play(playlist);
    else
    Play_all(playlist);
    }
    else if(strcmp(p, "show") == 0) 
    Show(playlist);
    else if(strcmp(p, "exit") == 0)
    break;
    else 
    printf("Comanda gresita!\n");
    }

    // La final eliberam memoria
    FreeQ(&playlist);

    return 0;
}