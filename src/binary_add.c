/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <stdio.h>

#include "malloc.h"

void init_leaf(chunk_t *chunk, size_t size)
{
    chunk->left = NULL;
    chunk->right = NULL;
    chunk->size = size - sizeof(chunk_t);
    //chunk->ptr = GET_DATA_ADDRESS(chunk);
    chunk->free = 0;
}

void *add_leaf(chunk_t *chunk, size_t size)
{
    printf("add leaf is called (w/ %zu) from %p (-> %zu)\n", size, chunk, chunk->size);
    //chunk_t *tmp;
    if (chunk->left == NULL) {
        //sbrk(sizeof(chunk_t));
        chunk->left = ((chunk_t *) ((ptrdiff_t) chunk + sizeof(chunk_t)));
        init_leaf(chunk->left, size);
        printf("be sure: %p <- %p -> %p\n", chunk->left, chunk, chunk->right);
        return (GET_DATA_ADDRESS(chunk->left));
    } else if (chunk->right == NULL) {
        //sbrk(sizeof(chunk_t));
        chunk->right = ((chunk_t *) ((ptrdiff_t) chunk->left + sizeof(chunk_t)));
        init_leaf(chunk->right, size);
        return (GET_DATA_ADDRESS(chunk->right));
    }
    if (chunk->right->size < size) {
        return (add_leaf(chunk->left, size));
    }
    else {
        return (add_leaf(chunk->right, size));
    }
    return (GET_DATA_ADDRESS(chunk));
}


/*
 * |------|
 * [*<>---|
 * [*<<>>
 */
