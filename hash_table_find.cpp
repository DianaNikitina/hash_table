#include "hash_table.h"

int64_t time_general = 0;

int HashTableFind(char **found_words, HashTable *hash_table)
{
    int count = 0;
    for (int j = 0; j < 1000; j++)
    {
        for (int i = 0; i < COUNT_FOUND_WORDS; i++)
        {
            count += Find(found_words[i], hash_table) ? 1 : 0;
        }
    }
    return count; 
}

WordEntry *Find(const char *word, HashTable *hash_table)
{
    uint64_t start = rdtsc();
    unsigned int hash = hash_table->HashFunction(word);
    size_t index = hash % hash_table->HashTableCapacity;
    uint64_t end = rdtsc();
    time_general += (int64_t)(end - start);

    list *bucket = &hash_table->Buckets[index];

    int current = bucket->cur_index;
    while (current != -1) {
        WordEntry *entry = bucket->data[current];
        if (entry && strcmp(entry->word, word) == 0) {
            return entry;
        }
        current = bucket->next[current];
    }
    return NULL;
}

WordEntry* FindInBucket(const list *bucket, const char *word)
{
    int cur = bucket->cur_index;
    while (cur != -1)
    {
        WordEntry *entry = bucket->data[cur];
        if (entry && strcmp(entry->word, word) == 0)
            return entry;
        cur = bucket->next[cur];
    }
    return NULL;
}

