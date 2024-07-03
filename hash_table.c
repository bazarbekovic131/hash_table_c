//
//  hash_table.c
//  memory_allocator
//
//  Created by Akha on 03.07.2024.
//

#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "hash_table.h"
#include "prime.h"

static Hash* hash_table_new_item(const char* key, const char* value) {
    Hash* i = malloc(sizeof(Hash));
    
    i->key = strdup(key);
    i->value = strdup(value); // why this func?
    return i;
}

// inits new HT. size defines how many items we can store. It's fixed at 53 for now
// expand it

HashTable* initHashTable(void) {
    HashTable* ht = malloc(sizeof(HashTable*));
    
    ht->size = 53;
    ht->count = 0;
    ht->items = calloc((size_t)ht->size, sizeof(Hash*));
    
    return ht;
}

static void deleteItem(Hash* item) {
    free(item->key);
    free(item->value);
    free(item);
}

void deleteHashTable(HashTable* ht) {
    for (int i = 0; i < ht->size; i++) {
        Hash* item = ht->items[i];
        if (item != NULL) {
            deleteItem(item);
        }
    }
    
    free(ht->items);
    free(ht);
}

static int hash(const char* string, const int a, const int m) {
    long hash = 0;
    
    const int string_length = (int)strlen(string);
    for (int i = 0; i < string_length; i++) {
        hash += (long)pow(a, string_length - (i+1)) * string[i];
        hash = hash % m;
    }
    return (int)hash;
}

static int get_hash(const char* string, const int num_buckets, const int attempt){
    const int hashA = hash(string, HT_PRIME_1, num_buckets);
    const int hashB = hash(string, HT_PRIME_2, num_buckets);
    return (hashA + (attempt * (hashB + 1))) % num_buckets;
}

void insert(HashTable* ht, const char* key, const char* value) {
    Hash* item = hash_table_new_item(key, value);
    int index = get_hash(item->key, ht->size, 0);
    Hash* currentItem = ht->items[index];
    int i = 1;
    while (currentItem != NULL && currentItem != &deleted_item) {
        if (currentItem != &deleted_item) {
            if (strcmp(currentItem->key, key) == 0) {
                deleteItem(currentItem);
                ht->items[index] = currentItem;
                return;
            }
        }
        
        index = get_hash(item->key, ht->size, i);
        currentItem = ht->items[index];
        i++;
    }
    ht->items[index] = item;
    ht->count++;
}

char* search(HashTable* ht, const char* key) {
    int index = get_hash(key, ht->size, 0);
    Hash* item = ht->items[index];
    
    int i = 1;
    while (item != NULL) {
        if (item != &deleted_item){
            if (strcmp(key, item->key) == 0) {
                return item->value;
            }
        }
        int index = get_hash(key, ht->size, i);
        item = ht->items[index];
        i++;
    }
    return NULL;
}



void hash_table_delete_item(HashTable* ht, const char* key) {
    int index = get_hash(key, ht->size, 0);
    Hash* item = ht->items[index];
    int i = 1;
    while (item != NULL) {
        if (item != &deleted_item) {
            if (strcmp(item->key, key) == 0) {
                deleteItem(item);
                ht->items[index] = &deleted_item;
            }
        }
        index = get_hash(key, ht->size, i);
        item = ht->items[index];
        i++;
    }
    ht->count--;
}
