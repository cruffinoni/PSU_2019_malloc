/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include "malloc.h"
#include <stdio.h>

chunk_t *master_chuck = NULL;
chunk_t *freed_chuck = NULL;

static void *init_master_chunk(size_t size)
{
    unsigned int s = 0;

    while ((size + sizeof(chunk_t)) >= s)
        s += MAP_SIZE;
    if ((master_chuck = (chunk_t *) sbrk(s)) == (void *) -1) {
        unlock_mutex();
        return (NULL);
    }
    master_chuck->size = size;
    master_chuck->free = 0;
    master_chuck->next = NULL;
    master_chuck->prev = NULL;
    master_chuck->last = master_chuck;
    master_chuck->alloc_mem = s;
    master_chuck->curr_mem = size;
    unlock_mutex();
    return (GET_DATA_ADDRESS(master_chuck));
}

static void *add_node(size_t size)
{
    chunk_t *last_chuck = master_chuck->last;

    //printf("Adding a node w/ %zu / %p\n", size, last_chuck);
    last_chuck->next = GET_NEXT_CHUNK(last_chuck);
    //printf("curr chunk: %p & Next chunk found: %p\n", last_chuck, last_chuck->next);
    last_chuck->next->size = size - sizeof(chunk_t);
    last_chuck->next->next = NULL;
    last_chuck->next->prev = last_chuck;
    last_chuck->next->free = 0;
    last_chuck->next->alloc_mem = master_chuck->alloc_mem;
    master_chuck->last = last_chuck->next;
    master_chuck->curr_mem += size;
    last_chuck->next->curr_mem = master_chuck->curr_mem;
    //printf("Curr : %p -> %p / %p\n", last_chuck->next, last_chuck->next->prev, master_chuck->last);
    //printf("(MALLOC) Last: %p & previous: %p\n", master_chuck->last, master_chuck->last->prev);
    unlock_mutex();
    return (GET_DATA_ADDRESS(last_chuck->next));
}

static void *add_and_resize(size_t size)
{
    unsigned int cpy = master_chuck->alloc_mem;

    //printf("Resizing w/ actual: %u\n", cpy);
    while ((size + sizeof(chunk_t) + master_chuck->curr_mem) >= master_chuck->alloc_mem)
        master_chuck->alloc_mem += MAP_SIZE;
    //printf("Resizing w/ new: %u ; total: %u\n", master_chuck->alloc_mem, master_chuck->alloc_mem - cpy);
    if (sbrk(master_chuck->alloc_mem - cpy) == (void *) -1) {
        master_chuck->alloc_mem = cpy;
        unlock_mutex();
        return (NULL);
    }
    return (add_node(size));
}

static void *add_chuck(size_t size)
{
    size += sizeof(chunk_t);
    //printf("Curr: %u & max: %u\n", master_chuck->curr_mem, master_chuck->alloc_mem);
    if ((master_chuck->curr_mem + size) >= master_chuck->alloc_mem)
        return (add_and_resize(size));
    else
        return (add_node(size));
}

void *malloc(size_t size)
//void *my_malloc(size_t size)
{
    write(1, "a", 1);
    //printf("\nMalloc called: %zu\n", size);
    //printf("Malloc, current master: %p & last: %p\n",
    //    master_chuck, master_chuck == NULL ? NULL : master_chuck->last);
    size = ALIGN_SIZE(size);
    lock_mutex();
    if (master_chuck == NULL)
        return (init_master_chunk(size));
    return (add_chuck(size));
}
