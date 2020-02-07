/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <stdio.h>

#include "malloc.h"

void *update_size(chunk_t *chunk, chunk_t *update)
{
    printf("Updating %p (%zu) w/ %p (%zu)\n", chunk, chunk->size, update, update->size);
    chunk->size -= update->size;
    return (GET_DATA_ADDRESS(update));
}

static void init_leaf(chunk_t *chunk, size_t size, size_t malloc_size)
{
    chunk->left = NULL;
    chunk->right = NULL;
    chunk->size = size;
    chunk->malloc_size = malloc_size;
    //chunk->ptr = GET_DATA_ADDRESS(chunk);
    chunk->free = 0;
}

chunk_t *add_leaf(chunk_t *chunk, size_t size, size_t malloc_size)
{
    printf("add leaf is called (w/ %zu) from %p (-> %zu)\n", size, chunk, chunk->size);
    if (chunk->left == NULL) {
        printf("Add left leaf w/ tmp: %zu\n", sizeof(chunk_t));
        chunk_t *tmp = ((chunk_t *) ((ptrdiff_t) chunk + (sizeof(chunk_t))));
        if (tmp->size != 0) {
            printf("double chunkt, size isn't 0\n");
            chunk->left = ((chunk_t *) ((ptrdiff_t) chunk + (sizeof(chunk_t) * 2)));
        }
        else
            chunk->left = tmp;
        init_leaf(chunk->left, GET_LEFT_CHUNK_SIZE(chunk, size),
            GET_SIZE_WO_STRUCT(size));
        return (chunk->left);
    } else if (chunk->right == NULL) {
        printf("Add right leaf (%zu)\n", size);
        chunk->right = ((chunk_t *) ((ptrdiff_t) chunk->left + sizeof(chunk_t)));
        init_leaf(chunk->right, size, GET_SIZE_WO_STRUCT(size));
        return (chunk->right);
    }
    if (chunk->right->malloc_size < malloc_size) {
        return (add_leaf(chunk->right, size, malloc_size));
    }
    else {
        return (add_leaf(chunk->left, size, malloc_size));
    }
}


/*
 * |------|
 * [*<>---|
 * [*-><><|
 * [*<><>-|
 */
