/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include "malloc.h"

#include <stdio.h>

static chunk_t *free_ptr(chunk_t *root, void *ptr)
{
    chunk_t *freed = NULL;

    if (GET_DATA_ADDRESS(root) == ptr) {
        root->free = 1;
        //printf("Setting %p (%zu) to free!\n", root, root->malloc_size);
        return (root);
    }
    if (root->left != NULL)
        freed = free_ptr(root->left, ptr);
    if (freed == NULL && root->right != NULL)
        freed = free_ptr(root->right, ptr);
    if (freed != NULL)
        root->size += freed->size;
    return (NULL);
}

//void my_free(void *ptr)
void free(void *ptr)
{
    if (ptr == NULL)
        return;
    //printf("ptr passed: %p\n", ptr);

    chunk_t *tmp = master_chuck;
    ptrdiff_t ptr_val = (ptrdiff_t) ptr;
    while (tmp != NULL && !PTR_IN_RANGE(tmp, ptr_val)) {
        //printf("%tx < %tx && %tx < %tx\n", (ptrdiff_t) tmp, ptr_val, ptr_val,
        //    (ptrdiff_t) tmp + (ptrdiff_t) tmp->size);
        tmp = tmp->next;
    }
    if (tmp == NULL) {
        //printf("Nothing found for ptr: %p\n", ptr);
        return;
    }
    //printf("%p must be inside %p w/ %zu\n", ptr, tmp, tmp->size);
    free_ptr(tmp, ptr);
    //printf("%p has now %zu as size\n", tmp, tmp->size);
}
