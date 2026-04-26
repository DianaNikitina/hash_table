#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <stdio.h>
#include <string.h>
#include <cstdlib>
#define TABLE_SIZE 4000

struct Data
{
    char *text;
    int count_str;

} ;


struct Hash_node
{
    char *word;
    int counter;
    struct Hash_node *next;
};

size_t size_data(FILE *file);
FILE *runfile (const char *head_file, const char *use_file);
void tokenize_array_data(char *array_data, char **words);
void add_hash_table(char **words, Hash_node **hash_node);
int simple_hash_func (char* word);
int first_letter_hash_func (char* word);
int len_word_hash_func (char* word);
int sum_ascii_hash_func (char* word);
int rol_hash_func (const char *word);
int crc32_hash_func (char *word);
int write_to_result_file(Hash_node **hash_table, const char *data_result);
int list_len(Hash_node *node);


#endif