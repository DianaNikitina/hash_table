#include "hash_table.h"

int simple_hash_func (char* word)
{
    return 0;
}

int first_letter_hash_func (char* word)
{
    if (word != NULL)
        return word[0];
    return 0;
}

int len_word_hash_func (char* word)
{
    int len = 0;
    while (word[len] != '\0')
        len++;
    return len;
}

int sum_ascii_hash_func (char* word)
{
    int ascii_sum = 0;
    int i = 0;
    while (word[i] != '\0')
    {
        ascii_sum += word[i];
        i++;
    }
    return ascii_sum;
}

static int rotl32 (int x, unsigned k)
{
    return (x << k) | (x >> (32 - k));
}

int rol_hash_func (const char *word)
{
    int h = 0;

    for (const unsigned char *p = (const unsigned char *)word; *p != '\0'; p++)
    {
        h = rotl32(h, 3);  
        h ^= *p;            
    }

    return h;
}


int crc32_hash_func (char *word)
{
    unsigned int crc = 0xFFFFFFFF;

    while (*word)
    {
        crc ^= (unsigned char)*word;

        for (int bit = 0; bit < 8; bit++)
        {
            if (crc & 1)
                crc = (crc >> 1) ^ 0xEDB88320;
            else
                crc >>= 1;
        }

        word++;
    }

    return int(crc ^ 0xFFFFFFFF);
}