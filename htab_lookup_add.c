// htab_lookup_add.c
// Riesenie IJC-DU2, priklad b), 20. 4. 2021
// Autor: Tomas Valent
// Prekladac: gcc 9.3
// Vyhladavanie (alebo pridanie key) v hash table

#include "htab.h"
#include "htab_struct.h"
#include <stdlib.h>
#include <stdio.h>

htab_pair_t *htab_lookup_add(htab_t *table, htab_key_t key)
{
    struct htab_item *newItem;
    newItem = malloc(sizeof(struct htab_item));
    if (newItem == NULL)
    {
        fprintf(stderr, "Chyba pri alokacii pamate\n");
        free(newItem);
        return NULL;
    }

    newItem->pair.key = malloc(sizeof(char) * (strlen(key) + 1));
    if (newItem->pair.key == NULL)
    {
        free(newItem);
        return NULL;
    }

    strcpy((char *)newItem->pair.key, key);
    newItem->next = NULL;
    size_t hash = (htab_hash_function(key) % table->arr_size);

    if (table->arr[hash] == NULL)
    {
        table->arr[hash] = newItem;
    }
    else
    {
        struct htab_item *ptr;
        ptr = table->arr[hash];
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = newItem;
    }

    table->size++;
    return &newItem->pair;
}
