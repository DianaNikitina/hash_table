#include "hash_table.h"


HashTableErr_t HashTableInit(HashTable *hash_table, size_t capacity)
{
    HashTableErr_t error = HASH_CORRECT;
    hash_table->HashTableCapacity = capacity;
    hash_table->Buckets = (list*) calloc (capacity, sizeof(list));
    if (!hash_table->Buckets)
    {
        printf("FROM HASH_TABLE: ERROR calloc array of lists\n");
        return HASH_FAILED_ALLOC_NODE;
    }
    printf("FROM HASH_TABLE: CORRECT calloc array of lists\n");
    printf("======================================\n\n");
    for (int i = 0; i < TABLE_SIZE; i++)
        ListInit(&hash_table->Buckets[i], COUNT_WORDS);

    hash_table->HashFunction = &simple_hash_func;

    HASH_TABLE_OK(hash_table, error);
    return HASH_CORRECT;
}