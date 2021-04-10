// htab_init
// Riesenie IJC-DU2, priklad a), 20. 4. 2021
// Autor: Tomas Valent
// Prekladac: gcc 9.3
// Konstruktor hash tabulky

#include "htab.h"
#include "htab_struct.h"

htab_t htab_init(size_t number)
{
    htab_t table = malloc (sizeof(htab_t) + n * sizeof(struct htab_item));
    if(table == NULL)
    {
        return NULL;
    }

    table->arr_size = n;
    table->size = 0;

    for(size_t i = 0; i < n; i++)
    {
        table->arr[i] = NULL;
    }

    return table;
}