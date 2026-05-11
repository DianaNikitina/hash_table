#include "hash_table.h"

void HashTableDump(HashTable *hash_table, HashTableErr_t error, const char *file, const char *function, int line)
{
    printf("======================================\n");
    printf("HashTableDump called from %s:%d (%s)\n", file, line, function);
    printf("Error code: %d", error);
    if (error == HASH_CORRECT) printf("no error");
    else if (error == HASH_BAD_POINTER_PASSED_IN_FUNC) printf("BAD_POINTER");
    else if (error == HASH_FAILED_ALLOC_NODE) printf("ALLOC_FAILED");
    else if (error == HASH_KEY_NOT_FOUND) printf("KEY_NOT_FOUND");
    else if (error == HASH_KEY_ALREADY_EXISTS) printf("KEY_EXISTS");
    else if (error == HASH_INVALID_TABLE_SIZE) printf("INVALID_SIZE");
    else if (error == HASH_FUNCTION_ERROR) printf("HASH_FUNC_ERROR");
    else if (error == HASH_DATA_CORRUPTED) printf("DATA_CORRUPTED");
    printf("\n\n");

    if (!hash_table) {
        printf("HashTable pointer is NULL\n");
        printf("======================================\n");
        return;
    }

    printf("HashTable address: %p\n", (void*)hash_table);
    printf("HashTableCapacity: %zu\n", hash_table->HashTableCapacity);
    printf("Size: %zu\n", hash_table->Size);
    printf("HashFunction: %p\n", (void*)hash_table->HashFunction);
    printf("Buckets array address: %p\n\n", (void*)hash_table->Buckets);

    if (!hash_table->Buckets) {
        printf("Buckets pointer is NULL\n");
        printf("======================================\n");
        return;
    }

    printf("======================================\n");
}