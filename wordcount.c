// wordcount.c
// Riesenie IJC-DU2, priklad b), 20. 4. 2021
// Autor: Tomas Valent
// Prekladac: gcc 9.3
// Prepisany subor z Cpp do C

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "htab.h"
#include "htab_struct.h"
#include "io.h"

/*
 Tuto velkost som vybral pretoze cislo by malo byt prvocislo a byt 1.3 nasobok hladaneho poctu hodnot
 vybral som 10 000 hodnot, takze hladame najblizsie cislo k hodnote 13 000 a to je 13 001
 Zdroj: http://cseweb.ucsd.edu/~kube/cls/100/Lectures/lec16/lec16-8.html
 */

#define MAX_SIZE 100
#define HTAB_SIZE 13001

int main()
{
    FILE *filename = stdin;

    char* word = malloc(MAX_SIZE * sizeof(char));
    if (!word)
    {
        fprintf(stderr, "Error in allocating memory.\n");
        return 1;
    }

    htab_t *table = htab_init(HTAB_SIZE);
    if (!table)
    {
        fprintf(stderr, "Error in allocating memory.\n");
        return 1;
    }

    int length = 0;
    while((length = read_word(word, MAX_SIZE, filename)) != EOF)
    {
        if (length >= MAX_SIZE)
        {
            fprintf(stderr, "Word is too long and was not read in its entirety.\n");
        }

        table->arr->pair = htab_lookup_add(table, word);

        if(!table->arr)
        {
            fprintf(stderr, "Word can not be put to table.\n");
            htab_free(table);
            htab_free(word);
            return 1;
        }
        table->size++;
    }

    for(unsigned int i; i < table->arr_size; i++)
    {
        struct htab_item *tmp = table->arr[i];
        if(table->arr[i] != NULL)
        {
            while(tmp)
            {
                printf("%s\t%d\n", table->arr[i]->pair.key, table->arr[i]->pair.value);
                if(tmp->next != NULL)
                    tmp=tmp->next;
                else
                    break;
            }
        }
    }

    free(word);
    htab_free(table);
    return 0;
}