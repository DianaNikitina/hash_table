#include "hash_table.h"

void DataTokenizeArray(char *array_data, char **words, const int count_words)
{
    int i = 0;
    const char *str = " ,.-!?\"';:()[]\n\t";
    char *saveptr = NULL;
    char *token = strtok_r (array_data, str, &saveptr);
    while (token != NULL && i < count_words)
    {
        words[i] = token;
        i++;
        token = strtok_r(NULL, str, &saveptr);
    }

    words[i] = NULL;
}