// htab_size.c
// Riesenie IJC-DU2, priklad b), 20. 4. 2021
// Autor: Tomas Valent
// Prekladac: gcc 9.3
// Zistenie velkosti tabulky

#include "htab.h"
#include "htab_struct.h"

size_t htab_size(htab_t *table);
{
    return table->size;
}