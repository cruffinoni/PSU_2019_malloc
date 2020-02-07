/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include "malloc.h"

#include <stdio.h>

static void free_ptr(chunk_t *root, void *ptr)
{
    if (GET_DATA_ADDRESS(root) == ptr) {
        printf("Setting %p (%zu) to free!\n", root, root->malloc_size);
        return;
    }
    if (root->left != NULL)
        free_ptr(root->left, ptr);
    if (root->right != NULL)
        free_ptr(root->right, ptr);
}

void my_free(void *ptr)
{
    if (ptr == NULL)
        return;
    printf("ptr passed: %p\n", ptr);

    chunk_t *tmp = master_chuck;
    ptrdiff_t ptr_val = (ptrdiff_t) ptr;
    while (tmp != NULL && !PTR_IN_RANGE(tmp, ptr_val)) {
        printf("%tx < %tx && %tx < %tx\n", (ptrdiff_t) tmp, ptr_val, ptr_val,
            (ptrdiff_t) tmp + (ptrdiff_t) tmp->size);
        tmp = tmp->next;
    }
    if (tmp == NULL) {
        printf("Nothing found for ptr: %p\n", ptr);
        return;
    }
    printf("%p must be inside %p\n", ptr, tmp);
    free_ptr(tmp, ptr);
}
