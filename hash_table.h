#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <immintrin.h>
#include <stdint.h>
#define TABLE_SIZE 4000

struct Data
{
    char *text;
    char **words_data;
    FILE *data;
    FILE *founded_words;
    size_t data_size;
    int count_str;

} ;


struct Hash_node
{
    char *word;
    int counter;
    struct Hash_node *next;
};

int init_data(Data *arrays_of_data);
size_t size_data(FILE *file);
FILE *runfile (const char *head_file, const char *use_file);
void tokenize_array_data(char *array_data, char **words);
void add_hash_table(char **words, Hash_node **hash_node);
int find_hash_table(char *word, Hash_node **hash_table);
int simple_hash_func (char* word);
unsigned int first_letter_hash_func (char* word);
unsigned int len_word_hash_func (char* word);
int sum_ascii_hash_func (char* word);
int rol_hash_func (const char *word);
unsigned int crc32_hash_func_intrinsic (char *word);
unsigned int crc32_hash_func_old (char *word);
unsigned int crc32_hash_func_intrinsic_optimized (char *word);
int write_to_result_file(Hash_node **hash_table, const char *data_result);
int list_len(Hash_node *node);


#endif