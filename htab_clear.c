// htab_clear.c
// Riesenie IJC-DU2, priklad b), 20. 4. 2021
// Autor: Tomas Valent
// Prekladac: gcc 9.3
// Vyprazdnenie hash tabulky

#include "htab.h"
#include "htab_struct.h"
#include <stdlib.h>

htab_t htab_clear(htab_t *table)
{
    htab_item *current;
    htab_item *erase;

    for(size_t i = 0; i < table->arr_size; i++)
    {
        current = table->arr[i];
        while(current != NULL)
        {
            toErase = current;
            current = current->next;
            free(erase->pair.key);
            free(erase);
        }
        table->arr[i] = NULL;
    }
    table->size = 0;
    return table;
}