#include "hash_table.h"

FILE *Runfile (const char *head_file, const char *use_file)
{
    FILE* file = fopen(head_file, use_file);

    if(!file)
    {
        printf("FROM DATA: ERROR OPENED FILE\n");
        return NULL;
    }
    printf("FROM DATA: CORRECT OPENED FILE\n");
    printf("======================================\n\n");
    return file;
}