#include "hash_table.h"

HashTableErr_t HashTableVerify(HashTable* hash_table)
{
    if (hash_table == NULL)
        return HASH_BAD_POINTER_PASSED_IN_FUNC;

    if (hash_table->Buckets == NULL)
        return HASH_BAD_POINTER_PASSED_IN_FUNC;

    if (hash_table->HashTableCapacity == 0)
        return HASH_INVALID_TABLE_SIZE;          

    if (hash_table->HashFunction == NULL)
        return HASH_FUNCTION_ERROR;       

    for (size_t i = 0; i < hash_table->HashTableCapacity; i++)
    {
        listErr_t list_err = LIST_CORRECT;
        LIST_OK(&hash_table->Buckets[i], list_err)
        if (list_err != LIST_CORRECT)
            return HASH_DATA_CORRUPTED;        
    }

    return HASH_CORRECT;
}