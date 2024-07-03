//
//  hash_table.h
//  memory_allocator
//
//  Created by Akha on 03.07.2024.
//

#ifndef hash_table_h
#define hash_table_h

typedef struct{
    char* key;
    char* value;
} Hash;

// note for myself: i did this on my own. I am so fcking good at setting a foundation!!!

typedef struct {
    int count; // count
    int size; // size of hashtable
    Hash** items; // double fcking pointer. i called keys, actually, but it's just items or pairs
} HashTable;

void insert(HashTable* ht, const char* key, const char* value);
char* search(HashTable* ht, const char* key);
void delete(HashTable* ht, const char* key);

static Hash deleted_item = {NULL, NULL};

#endif /* hash_table_h */
