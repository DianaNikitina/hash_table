#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define CANARY 15;
#define LIST_OK(list, error) error = ListVerify(list); if (error) ListDump(list, error,  __FILE__, __FUNCTION__, __LINE__);

struct WordEntry;
typedef struct WordEntry* list_elem_t; 

enum listErr_t 
{
    LIST_CORRECT                    = 0,
    LIST_BAD_POINTER_PASSED_IN_FUNC = 1,
    LIST_CRASH_IN_CALLOC_OF_NODE    = 2,
    LIST_DATA_CORRUPTED             = 3   
};

struct WordEntry
{
    char *word;
    int counter_word;
};

struct list 
{
    list_elem_t *data;
    int* next;
    int* prev;
    size_t capacity;
    size_t size;
    int free;
    int cur_index; 
};

int ListInit(list* list, const size_t capacity);
void FillOutData(list* list);
void FillOutNext(list* list);
void FillOutPrev(list* list);
void ListInsertFirst(list *list, int index, list_elem_t elem);
int ListDump(list *list, listErr_t error, const char* file, const char* function, int line);
listErr_t ListVerify(list* list);
int ListAdd(list *list, list_elem_t elem, int index);
bool ListAlmostFull(const list *list);
int ListSizeExtend(list *list);
void ListDestroy(list *list);

#endif