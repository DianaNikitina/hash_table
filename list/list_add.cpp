#include "list.h"


bool ListAlmostFull(const list *list)
{
    return list->free == -1;
}


int ListSizeExtend(list *list)
{
    size_t new_size = list->capacity * 2;
    if (new_size == 0) return -1;

    list_elem_t *new_data = (list_elem_t *)realloc(list->data, new_size * sizeof(list_elem_t));
    int *new_next = (int *)realloc(list->next, new_size * sizeof(int));
    int *new_prev = (int *)realloc(list->prev, new_size * sizeof(int));

    if (new_data == NULL || new_next == NULL || new_prev == NULL) 
    {
        free(new_data); 
        free(new_next); 
        free(new_prev);
        fprintf(stderr, "Error in ListSizeExtend() in realloc.\n");
        return -1;
    }

    list->data = new_data;
    list->next = new_next;
    list->prev = new_prev;


    for (size_t i = list->capacity; i < new_size; i++) {
        list->data[i] = NULL;
        list->prev[i] = -1;                    
        list->next[i] = (i == new_size - 1) ? -1 : (int)(i + 1); 
    }

    
    if (list->free == -1) {
        
        list->free = (int)list->capacity;
    } else {
        // Находим последний свободный узел
        int cur = list->free;
        while (list->next[cur] != -1) {
            cur = list->next[cur];
        }
        list->next[cur] = (int)list->capacity;  // подсоединяем новый блок
    }

    list->capacity = new_size;
    return 0;
}

/**
 * @brief Вспомогательная функция для вставки самого первого элемента в абсолютно пустой список (необязательна, оставлена для обратной совместимости).
 */
void ListInsertFirst(list *list, int index, list_elem_t elem)
{
    int new_free = list->next[list->free];

    list->data[list->free] = elem;
    list->next[list->free] = 0;               // следующий — 0 (голова)
    list->prev[list->free] = index;           // предыдущий — переданный индекс

    list->next[index] = list->free;
    list->prev[index] = list->free;

    list->free = new_free;
}

/**
 * @brief Добавляет элемент в список.
 * @param list Указатель на список.
 * @param elem Указатель на запись WordEntry.
 * @param index Индекс в массиве, **после** которого вставить элемент.
 *              Если index == -1 — вставка в начало списка (новая голова).
 * @return Индекс нового узла при успехе, -1 при ошибке.
 */
int ListAdd(list *list, list_elem_t elem, int index)
{
    // ===== Вставка в начало =====
    if (index == -1) {
        if (ListAlmostFull(list)) {
            if (ListSizeExtend(list) != 0)
                return -1;
        }
        if (list->free == -1) return -1;

        int node = list->free;
        list->free = list->next[node];   // убираем узел из цепочки свободных

        list->data[node] = elem;
        list->prev[node] = -1;            // перед новым узлом ничего нет
        list->next[node] = list->cur_index; // старую голову делаем следующей

        if (list->cur_index != -1)        // если список был не пуст
            list->prev[list->cur_index] = node;

        list->cur_index = node;           // новая голова
        list->size++;
        return node;                      // успех
    }

    // ===== Вставка после заданного index =====
    if (index < 0 || index >= (int)list->capacity || list->free > (int)list->capacity) {
        fprintf(stderr, "Error in ListAdd(): invalid index or free pointer.\n");
        return -1;
    }

    // --- Устаревшая проверка, которая при новой инициализации не срабатывает ---
    // Оставляем её для возможной совместимости со старым кодом, но она не нужна
    if (index == 0 && list->next[0] == 0 && list->prev[0] == 0) {
        ListInsertFirst(list, index, elem);
        return 1;
    }
    // -----------------------------------------------------------------

    if (ListAlmostFull(list)) {
        if (ListSizeExtend(list) != 0)
            return -1;
    }
    if (list->free == -1) return -1;

    int new_node = list->free;
    list->free = list->next[new_node];

    list->data[new_node] = elem;
    list->next[new_node] = list->next[index];
    list->prev[new_node] = index;

    // Если после index был узел, обновляем его prev
    if (list->next[index] != -1)
        list->prev[list->next[index]] = new_node;

    list->next[index] = new_node;
    list->size++;
    return 0;
}