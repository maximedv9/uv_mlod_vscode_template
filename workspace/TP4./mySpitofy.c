// gcc -W -Wall linkedListOfMusic.c mySpitofy.c -o mySpitofy

// valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./mySpitofy <music.csv> out.csv

#include "linkedListeOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// ============
// main
// ============

int main()
{
    Liste musicList;
    FILE *fichierMusic = fopen("music.csv", "r");
    musicList = creer(lineToMusic());
    while (!feof(fichierMusic))
    {
        musicList = ajoutFin_i(lineToMusic(), musicList);
    }

    afficheListe_i(musicList);
    detruire_i(musicList);
    fclose(fichierMusic);

    return 0;
}