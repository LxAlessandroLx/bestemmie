#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_FILE  "bestemmie.txt"
#define OUTPUT_FILE "porcodio.h"

int main()
{
    FILE *input = fopen(INPUT_FILE, "r");
    if (input == NULL)
    {
        fprintf(stderr, "Cannot open file " INPUT_FILE "!\n");
        fclose(input);
        return EXIT_FAILURE;
    }

    FILE *output = fopen(OUTPUT_FILE, "w");
    if (output == NULL)
    {
        fprintf(stderr, "Cannot open file " OUTPUT_FILE "!\n");
        fclose(output);
        return EXIT_FAILURE;
    }

    fprintf(output, "\
#ifndef PORCODIO_H\n\
#define PORCODIO_H\n\
\n\
#include <stdio.h>\n\
#include <stdlib.h>\n\
#include <time.h>\n\
\n\
#define NUMERO_BESTEMMIE sizeof(bestemmie)/sizeof(bestemmie[0])\n\
\n\
static const char* bestemmie[] = {\n");

    char line [1024];
    while(fgets(line, sizeof(line), input) != NULL)
    {
        line[strlen(line)-1] = '\0';
        fprintf(output, "\t\"%s\",\n", line);
    }

    fprintf(output, "\
};\n\
static void bestemmia()\n\
{\n\
    srand(time(NULL));\n\
\n\
    puts(bestemmie[rand()%%NUMERO_BESTEMMIE]);\n\
}\n\
\n\
#endif // PORCODIO_H\n\
");

    fclose(output);

    return EXIT_SUCCESS;
}
