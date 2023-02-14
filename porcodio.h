#ifndef PORCODIO_H
#define PORCODIO_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMERO_BESTEMMIE sizeof(bestemmie)/sizeof(bestemmie[0])

static const char* bestemmie[] = {
};

static void bestemmia()
{
    srand(time(NULL));

    puts(bestemmie[rand()%NUMERO_BESTEMMIE]);
}

#endif // PORCODIO_H
