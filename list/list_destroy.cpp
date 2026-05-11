#include "list.h"

void ListDestroy(list *list)
{
    free(list->data);
    free(list->next);
    free(list->prev);
    list->data = NULL;
    list->next = NULL;
    list->prev = NULL;
    list->capacity = 0;
    list->free = 0;
}