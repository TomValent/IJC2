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
        htab_item *newItem = malloc(sizeof(htab_item_t));
        if(newItem->pair.key == NULL)
            return NULL;
        newItem.key = malloc((strlen(key) + 1) * sizeof(char));    //alokacia pamati pre key a jeho presun
        if(newItem->pair.key == NULL)
            return NULL;
        memcpy(newItem->pair.key, key, (strlen(key) + 1));
        newItem->next = NULL;
        newItem->pair.value = 0;

        table->size++;
        table->arr[index] = newItem;                 //pridani do tabulky
        return &(htab_item_t->pair);
    }

    while (item->next != NULL)                       //ine polozky
    {
        if (strlen(key) == strlen(item->pair.key))
        {
            if (strncmp(key, item->pair.key, strlen(key)) == 0)
            {
                return &(htab_item_t->pair);
            }
        }
        item = item->next;
    }

    if (strlen(key) == strlen(item->pair.key))            //posledna polozka
    {
        if (strncmp(key, item->pair.key, strlen(key)) == 0)
        {
            return &(htab_item_t->pair);
        }
    }

    htab_pair_t *newItem = malloc(sizeof(struct htab_pair_t));
    if(newItem == NULL)
    {
        return NULL;
    }

    newItem.key = malloc((strlen(key) + 1) * sizeof(char));    //alokacia pamati pre key a jeho presun
    if(newItem->key == NULL)
        return NULL;
    memcpy(newItem.key, key, (strlen(key) + 1));
    newItem->next = NULL;
    newItem.value = 0;

    newItem->next = newItem;
    table->size++;

    return &(htab_item_t->pair);
}