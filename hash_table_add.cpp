#include "hash_table.h"

HashTableErr_t HashTableAdd(char **words, HashTable *hash_table)
{
    if (!words || !hash_table)
        return HASH_BAD_POINTER_PASSED_IN_FUNC;

    for (int i = 0; words[i] != NULL; i++)
    {
        unsigned int hash = hash_table->HashFunction(words[i]);
        size_t index = hash % hash_table->HashTableCapacity;
        list *bucket = &hash_table->Buckets[index];

        WordEntry *entry = FindInBucket(bucket, words[i]);
        if (entry)
        {
            entry->counter_word++;
            hash_table->Size++;
            continue;
        }

        entry = (WordEntry*)calloc(1, sizeof(WordEntry));
        if (!entry)
            return HASH_FAILED_ALLOC_NODE;

        entry->word = strdup(words[i]);
        if (!entry->word)
        {
            free(entry);
            return HASH_FAILED_ALLOC_NODE;
        }
        entry->counter_word = 1;

        if (ListAdd(bucket, entry, -1) < 0)
        {
            free(entry->word);
            free(entry);
            return HASH_BAD_POINTER_PASSED_IN_FUNC;
        }
        hash_table->Size++;
    }

    return HASH_CORRECT;
}