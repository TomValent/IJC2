// io.c
// Riesenie IJC-DU2, priklad b), 20. 4. 2021
// Autor: Tomas Valent
// Prekladac: gcc 9.3
// Ziskanie dlzky slova

#include "io.h"

int read_word(char *s, int max, FILE *f)
{
    if(!filename)
    {
        fprintf(stderr, "File cannot be NULL.\n");
        return EOF;
    }

    int character = 0;

    while((character = fgetc(f)) && isspace(character))
    {
        //skip first space
        ;
    }

    if (character == EOF)
    {
        return character;
    }

    int counter = 0;
    s[counter++] = character;

    while(counter < (max - 1))
    {
        character = fgetc(f);
        if(character == EOF || isspace(character))
        {
            break;
        }
        s[counter++] = character;
    }

    s[counter] = '\0';

    if((max - 1) == counter)
    {
        while((character = fgetc(f)) != EOF && !isspace(character))
        {
            counter++;
        }
    }
    return counter;
}