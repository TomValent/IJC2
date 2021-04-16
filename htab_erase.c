// htab_erase.c
// Riesenie IJC-DU2, priklad b), 20. 4. 2021
// Autor: Tomas Valent
// Prekladac: gcc 9.3
// Vymazanie prvku tabulky

#include "htab.h"
#include "htab_struct.h"
#include <stdlib.h>

bool htab_erase(htab_t *table, htab_key_t key)
{
    size_t hash = htab_hash_function(key);
    size_t index = hash % table->arr_size;
    struct htab_item *item = table->arr[index];

    if (item->pair.key == key)
    {
        item = item->next;
        free(item->next);
        free((char *)item->pair.key);
        return true;
    }

    while (item->next != NULL)
    {
        if (item->next->pair.key == key)
        {
            if(item->next->next != NULL)
            {
                item->next = item->next->next;
                free(item->next->next);
                free(item->next);
                return true;
            }
            else
            {
                free(item->next->next);
                free(item->next);
                return true;
            }
        }
        else
        {
            item = item->next;
        }
    }
    return false;
}