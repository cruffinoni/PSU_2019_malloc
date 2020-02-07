/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include "malloc.h"
#include <stdio.h>

chunk_t *master_chuck = NULL;

static void *init_master_chunk(size_t size)
{
    unsigned int s = 0;


    while ((size + sizeof(chunk_t)) >= s)
        s += MAP_SIZE;

    if ((master_chuck = (chunk_t *) sbrk(s)) == (void *) -1) {
        unlock_mutex();
        return (NULL);
    }
    //printf("Master chuck is: %p\n", master_chuck);
    master_chuck->size = size;
    master_chuck->free = 0;
    master_chuck->next = NULL;
    master_chuck->prev = NULL;
    master_chuck->last = master_chuck;
    master_chuck->alloc_mem = s;
    master_chuck->curr_mem = size;
    unlock_mutex();
    //printf("[master] Returning... %p\n", GET_DATA_ADDRESS(master_chuck));
    return (GET_DATA_ADDRESS(master_chuck));
}

static void *add_node(size_t size)
{
    chunk_t *last_chuck = master_chuck->last;

    //printf("add node called!!\n");
    last_chuck->next = GET_NEXT_CHUNK(last_chuck);
    //printf("last: %p & next: %p\n", last_chuck, last_chuck->next);
    last_chuck->next->size = size - sizeof(chunk_t);
    last_chuck->next->next = NULL;
    last_chuck->next->prev = last_chuck;
    last_chuck->next->free = 0;
    last_chuck->next->alloc_mem = master_chuck->alloc_mem;
    master_chuck->last = last_chuck->next;
    master_chuck->curr_mem += size;
    unlock_mutex();
    //printf("Returning... %p\n", GET_DATA_ADDRESS(last_chuck->next));
    return (GET_DATA_ADDRESS(last_chuck->next));
}

static void *add_and_resize(size_t size)
{
    unsigned int cpy = master_chuck->alloc_mem;

    while ((size + sizeof(chunk_t) + master_chuck->curr_mem) >= master_chuck->alloc_mem)
        master_chuck->alloc_mem += MAP_SIZE;
    //printf("real size called??\n");
    //
    //printf("resizing chuck w/ %zu\n", real_size);
    if (sbrk(master_chuck->alloc_mem - cpy) == (void *) -1) {
        master_chuck->alloc_mem = cpy;
        unlock_mutex();
        return (NULL);
    }
    //master_chuck->alloc_mem += real_size;
    return (add_node(size));
}

static void *add_chuck(size_t size)
{
    size += sizeof(chunk_t);
    //printf("Sizes: %u & %u w/ %zu & %zu\n", master_chuck->alloc_mem, master_chuck->curr_mem,
    //    sizeof(chunk_t), size);
    //printf("Condition: %zu >= %u\n", (master_chuck->curr_mem + size), master_chuck->alloc_mem);
    if ((master_chuck->curr_mem + size) >= master_chuck->alloc_mem)
        return (add_and_resize(size));
    else {
        return (add_node(size));
    }
}

void *malloc(size_t size)
{
    write(1, "a", 1);
    //printf("... %zu & %zu\n", sizeof(chunk_t), sizeof(t_memory_chunk));
    // TODO: Check la size (<0 ou > ???)
    //printf("malloc called w/ %zu\n", size);
    size = ALIGN_SIZE(size);
    lock_mutex();
    if (master_chuck == NULL) {
        //printf("Init master chunk...\n");
        return (init_master_chunk(size));
    }
    return (add_chuck(size));
}
