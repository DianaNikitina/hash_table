#include "list.h"

listErr_t ListVerify(list *lst) 
{
    if (!lst)
        return LIST_BAD_POINTER_PASSED_IN_FUNC;
    if (!lst->data || !lst->next || !lst->prev)
        return LIST_BAD_POINTER_PASSED_IN_FUNC;
    if (lst->capacity == 0)
        return LIST_CRASH_IN_CALLOC_OF_NODE;

    if (lst->cur_index < -1 || lst->cur_index >= (int)lst->capacity)
        return LIST_DATA_CORRUPTED;

    if (lst->free < -1 || lst->free >= (int)lst->capacity)
        return LIST_DATA_CORRUPTED;
    return LIST_CORRECT;
}