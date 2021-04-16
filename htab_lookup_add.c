// htab_lookup_add.c
// Riesenie IJC-DU2, priklad b), 20. 4. 2021
// Autor: Tomas Valent
// Prekladac: gcc 9.3
// Vyhladavanie (alebo pridanie key) v hash table

#include "htab.h"
#include "htab_struct.h"
#include <stdlib.h>

htab_pair_t* htab_lookup_add(htab_t *table, htab_key_t key)
{
    size_t hash = htab_hash_function(key);
    size_t index = hash % table->arr_size;
    struct htab_item *item = table->arr[index];

    if (item == NULL)                                                    //tabulka je prazdna, vytvorim prvy prvok
    {
        struct htab_item *newItem = malloc(sizeof(struct htab_item));
        if(newItem->pair.key == NULL)
            return NULL;
        newItem->pair.key = malloc((strlen(key) + 1) * sizeof(char));    //alokacia pamati pre key a jeho presun
        if(newItem->pair.key == NULL)
            return NULL;
        memcpy((char *)newItem->pair.key, key, (strlen(key) + 1));
        newItem->next = NULL;
        newItem->pair.value = 0;

        table->size++;
        table->arr[index] = newItem;                 //pridani do tabulky
        return &(item->pair);
    }

    while (item->next != NULL)                       //ine polozky
    {
        if (strlen(key) == strlen(item->pair.key))
        {
            if (strncmp(key, item->pair.key, strlen(key)) == 0)
            {
                return &(item->pair);
            }
        }
        item = item->next;
    }

    if (strlen(key) == strlen(item->pair.key))            //posledna polozka
    {
        if (strncmp(key, item->pair.key, strlen(key)) == 0)
        {
            return &(item->pair);
        }
    }

    struct htab_item *newItem = malloc(sizeof(struct htab_item));
    if(newItem == NULL)
    {
        return NULL;
    }

    newItem->pair.key = malloc((strlen(key) + 1) * sizeof(char));    //alokacia pamati pre key a jeho presun
    if(newItem->pair.key == NULL)
        return NULL;
    memcpy((char *)newItem->pair.key, key, (strlen(key) + 1));
    newItem->next = NULL;
    newItem->pair.value = 0;

    newItem->next = newItem;
    table->size++;

    return &(newItem->pair);
}