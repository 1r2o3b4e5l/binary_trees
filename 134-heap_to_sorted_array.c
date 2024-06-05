#include "binary_trees.h"
#include <stdlib.h>

void heap_to_sorted_array_helper(heap_t *heap, int *array, size_t *index)
{
    if (heap == NULL)
        return;

    heap_to_sorted_array_helper(heap->right, array, index);
    array[*index] = heap->n;
    (*index)++;
    heap_to_sorted_array_helper(heap->left, array, index);
}

int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int *sorted_array;
    size_t array_size = 0;

    if (heap == NULL || size == NULL)
        return NULL;

    array_size = binary_tree_size(heap);
    sorted_array = malloc(sizeof(int) * array_size);
    if (sorted_array == NULL)
        return NULL;

    heap_to_sorted_array_helper(heap, sorted_array, &array_size);
    *size = array_size;
    return sorted_array;
}

