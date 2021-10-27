#pragma once

#include "LinkedList.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// ============
// Types
// ============

typedef struct Music
{
    char *name;
    char *artist;
    char *album;
    char *genre;
    int discNumber;
    int trackNumber;
    int year;
} Music;

char *scanLine();
Music *lineToMusic();

// ============
// External Functions
// ============

extern void afficheElement(Element e);
extern void detruireElement(Element e);
extern bool equalsElement(Element e1, Element e2);
