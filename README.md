# porcodio.h
Libreria header-only per la generazione di bestemmie in C

## Utilizzo
```c
#include "porcodio.h"

int main()
{
    srand(time(NULL));

    bestemmia();
}
```

## generator.c
File per autogenerare la libreria porcodio.h, la lista delle bestemmie deve essere contenuta nel file `bestemmie.txt`, una bestemmia per riga
