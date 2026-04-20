#include "hash_table.h"

FILE *runfile (const char *head_file, const char *use_file)
{
    FILE* file = fopen(head_file, use_file);

    if(!file)
    {
        printf("ERROR OPENED FILE\n");
        return NULL;
    }
    printf("CORRECT OPENED FILE\n");
    return file;
}