/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include "malloc.h"

chunk_t *master_chuck = NULL;
chunk_t *freed_chuck = NULL;

static void *init_master_chunk(size_t size)
{
    unsigned int s = MAP_SIZE;

    while ((size + STRUCT_SIZE) >= s) {
        s += MAP_SIZE;
    }
    if ((master_chuck = (chunk_t *) sbrk(s)) == (void *) -1)
        return (NULL);
    master_chuck->size = size;
    master_chuck->free = 0;
    master_chuck->addr = (void *)((void *)master_chuck + STRUCT_SIZE);
    master_chuck->hf_mem = 0;
    master_chuck->next = NULL;
    master_chuck->prev = NULL;
    master_chuck->last = master_chuck;
    master_chuck->alloc_mem = s;
    master_chuck->curr_mem = size + STRUCT_SIZE;
    return (GET_DATA_ADDRESS(master_chuck));
}

static void *add_node(size_t size)
{
    chunk_t *last_chuck = master_chuck->last;

    last_chuck->next = GET_NEXT_CHUNK(last_chuck);
    last_chuck->next->addr = (void *)(last_chuck->addr +
        (last_chuck->size + STRUCT_SIZE));
    last_chuck->next->size = size;
    last_chuck->next->next = NULL;
    last_chuck->next->prev = last_chuck;
    last_chuck->next->free = 0;
    last_chuck->next->alloc_mem = master_chuck->alloc_mem;
    master_chuck->last = last_chuck->next;
    master_chuck->curr_mem += size + STRUCT_SIZE;
    last_chuck->next->curr_mem = master_chuck->curr_mem;
    return (GET_DATA_ADDRESS(last_chuck->next));
}

static void *reuse_freed_node(size_t size)
{
    chunk_t *tmp = master_chuck;
    uint higher_size = 0;

    while (tmp != NULL) {
        if (tmp->size >= size && tmp->free) {
            tmp->free = 0;
            master_chuck->hf_mem = higher_size;
            return ((void *) ((void *) tmp + STRUCT_SIZE));
        }
        if (tmp->size > higher_size && tmp->free)
            higher_size = tmp->size;
        tmp = tmp->next;
    }
    return (NULL);
}

static void *add_chuck(size_t size)
{
    unsigned int cpy = master_chuck == NULL ? 0 : master_chuck->alloc_mem;

    if (master_chuck != NULL && master_chuck->hf_mem >= size)
        return (reuse_freed_node(size));
    if ((master_chuck->curr_mem + size + STRUCT_SIZE) >= master_chuck->alloc_mem) {
        while (REAL_SIZE(size) >= master_chuck->alloc_mem)
            master_chuck->alloc_mem += MAP_SIZE;
        if (sbrk(master_chuck->alloc_mem - cpy) == (void *) -1) {
            master_chuck->alloc_mem = cpy;
            return (NULL);
        }
    }
    return (add_node(size));
}

void *malloc(size_t size)
{
    size = ALIGN_SIZE(size);
    if (master_chuck == NULL)
        return (init_master_chunk(size));
    return (add_chuck(size));
}
