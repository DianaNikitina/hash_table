#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <immintrin.h>
#include <stdint.h>
#include "list/list.h"
#define COUNT_WORDS 80021
#define TABLE_SIZE 1009
#define COUNT_FOUND_WORDS 111217
#define HASH_TABLE_OK(hash_table, error) \
    error = HashTableVerify(hash_table); \
    if (error) \
        HashTableDump(hash_table, error,  __FILE__, __FUNCTION__, __LINE__);


struct HashTable
{
    size_t HashTableCapacity;
    size_t Size;
    list* Buckets;
    unsigned int (*HashFunction) (const char* word);
};

enum HashTableErr_t 
{
    HASH_CORRECT                           = 0,
    HASH_BAD_POINTER_PASSED_IN_FUNC        = 1,
    HASH_FAILED_ALLOC_NODE                 = 2,   
    HASH_KEY_NOT_FOUND                     = 3,   
    HASH_KEY_ALREADY_EXISTS                = 4,  
    HASH_TABLE_IS_FULL                     = 5,  
    HASH_FAILED_REALLOC_TABLE              = 6,   
    HASH_NULL_KEY_PASSED                   = 7,   
    HASH_INVALID_TABLE_SIZE                = 8,   
    HASH_FUNCTION_ERROR                    = 9,   
    HASH_DATA_CORRUPTED                    = 10   
};

// system ("gnuplot")
// popen ()
// fprintf("plot %s.csv") 
// array struct, jpg, csv, hash_func

extern int64_t time_general;

extern "C" unsigned int crc32_hash_asm_no_strlen(const char* word);

static inline uint64_t rdtsc() {
    return __rdtsc();
}

struct Data
{
    char *text;
    char *text_founded;
    char **words_data;
    char **founded_words_data;

};

struct Files
{
    FILE *data;
    FILE *founded_words;
    size_t data_size;
    size_t founded_words_size;
    int count_str; 
} ;

HashTableErr_t HashTableInit(HashTable *hash_table, size_t capacity);
HashTableErr_t HashTableAdd(char **words, HashTable *hash_table);
int DataInit(Data *DataArrays, Files *Files);
FILE *Runfile (const char *head_file, const char *use_file);
size_t DataSize(FILE *file);
void DataProcessing(Data *DataArrays, Files *Files);
HashTableErr_t HashTableVerify(HashTable* hash_table);
void HashTableDump(HashTable *hash_table, HashTableErr_t error, const char *file, const char *function, int line);
void DataTokenizeArray(char *array_data, char **words, const  int table_size);
int HashTableFind(char **found_words, HashTable *hash_table);
WordEntry* FindInBucket(const list *bucket, const char *word);
WordEntry *Find(const char *word, HashTable *hash_table);

//======================================
// hash func
//======================================
unsigned int simple_hash_func                    (const char* word);
unsigned int first_letter_hash_func              (const char* word);
unsigned int len_word_hash_func                  (const char* word);
unsigned int sum_ascii_hash_func                 (const char* word);
unsigned int rol_hash_func                       (const char *word);
unsigned int crc32_hash_func_intrinsic           (const char *word);
unsigned int crc32_hash_func_old                 (const char *word);
unsigned int crc32_hash_func_intrinsic_optimized (const char *word);
//======================================
// end 
//======================================

int          WriteToFile                         (HashTable *hash_table, const char *head_file);
void         HashTableDestroy                    (HashTable *hash_table);
void         DataDestroy                         (Data *DataArrays, Files *Files);


#endif