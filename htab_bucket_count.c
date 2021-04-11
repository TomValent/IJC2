// htab_bucket_count.c
// Riesenie IJC-DU2, priklad b), 20. 4. 2021
// Autor: Tomas Valent
// Prekladac: gcc 9.3
// Zistenie pocet prvkov pola

#include "htab.h"
#include "htab_struct.h"

size_t htab_bucket_count(htab_t *table);
{
    return table->arr_size;
}