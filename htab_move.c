// htab_move.c
// Riesenie IJC-DU2, priklad b), 20. 4. 2021
// Autor: Tomas Valent
// Prekladac: gcc 9.3
// Move konstruktor hash tabulky

#include "htab.h"
#include "htab_struct.h"

htab_t htab_move(size_t number, htab_t *t2)
{
    htab_t table = htab_init(number);   //nova tabulka so zadanou velkostou
    size_t hash = htab_hash_function(key);
    size_t index = hash % table->arr_size;
    htab_item *item = table->arr[index];

    if(table == NULL)
        return NULL;

    for(size_t i; i < table->arr_size; i++)
    {
        table[index] = htab_lookup_add(&t2, index);
    }

    t2 = htab_clear(t2);
    return table;
}