#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *scanLine()
{
    int maxLineSize = 255;
    char c, *line = calloc(maxLineSize + 1, sizeof(char));

    scanf("%250[^\n]", line);

    if ((c = getchar()) != '\n')
    {
        /* we did not get all the line */
        line[250] = '[';
        line[251] = line[252] = line[253] = '.';
        line[254] = ']';
        // line[255] = '\0'; // useless because already initialized by calloc

        // let's skip all chars untli the end of line
        while (((c = getchar()) != '\n') && c != EOF)
            ;
    }

    return line;
}

Music *lineToMusic()
{
    Music *music;
    music = (Music *)malloc(sizeof(Music));
    char *line = scanLine();
    char *lineCopy = strdup(line);

    music->name = strsep(&lineCopy, ",");
    music->artist = strsep(&lineCopy, ",");
    music->album = strsep(&lineCopy, ",");
    music->genre = strsep(&lineCopy, ",");
    music->discNumber = atoi(strsep(&lineCopy, ","));
    music->trackNumber = atoi(strsep(&lineCopy, ","));
    music->year = atoi(strsep(&lineCopy, ","));

    //free();
    return music;
}

void afficheElement(Element e)
{
    Music *music = (Music *)e;
    printf("%s,", music->name);
    printf("%s,", music->artist);
    printf("%s,", music->album);
    printf("%s,", music->genre);
    printf("%i", music->discNumber);
    printf("%i", music->trackNumber);
    printf("%i", music->year);
}

void detruireElement(Element e)
{
    Music *music = (Music *)e;
    free(music->name);
    music->name = NULL;
    free(music->album);
    music->album = NULL;
    free(music->artist);
    music->artist = NULL;
    free(music->genre);
    music->genre = NULL;
    free(music);
    music = NULL;
}

bool equalsElement(Element e, Element f)
{
    Music *music1 = (Music *)e;
    Music *music2 = (Music *)f;
    return ((strcmp(music1->name, music2->name) == 0) && (strcmp(music1->artist, music2->artist) == 0) && (strcmp(music1->album, music2->album) == 0) && (strcmp(music1->genre, music2->genre) == 0));
}
