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
    chunk->size = size;
    chunk->ptr = GET_NEXT_CHUNK(chunk);
    chunk->free = 0;
}

void add_leaf(chunk_t *chunk, size_t size)
{
    printf("add leaf is called (w/ %zu)\n", size);
    //chunk_t *tmp;
    if (chunk->left == NULL) {
        sbrk(sizeof(chunk_t));
        chunk->left = ((chunk_t *) ((ptrdiff_t) chunk + sizeof(chunk_t)));
        init_leaf(chunk->left, size);
    } else if (chunk->right == NULL) {
        sbrk(sizeof(chunk_t));
        chunk->right = ((chunk_t *) ((ptrdiff_t) chunk + sizeof(chunk_t)));
        init_leaf(chunk->right, size);
    }
}
