// htab_free.c
// Riesenie IJC-DU2, priklad b), 20. 4. 2021
// Autor: Tomas Valent
// Prekladac: gcc 9.3
// Uvolnenie hash tabulky

#include "htab.h"
#include "htab_struct.h"
#include <stdlib.h>

void htab_free(htab_t *table)
{
    htab_clear(table);
    free(table);
}