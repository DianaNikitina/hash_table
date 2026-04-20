#include "hash_table.h"

void tokenize_array_data(char *array_data, char **words)
{
    int i = 0;
    const char *str = " ";
    char *saveptr = NULL;
    char *token = strtok_r (array_data, str, &saveptr);
    while (token != NULL && i < 4000)
    {
        words[i] = token;
        i++;
        token = strtok_r(NULL, str, &saveptr);
    }

    words[i] = NULL;
}