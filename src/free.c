/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <signal.h>
#include "malloc.h"

chunk_t *freed_chuck = NULL;

#include <stdio.h>

static void move_brk()
{
    chunk_t *tmp = master_chuck->last;

    //printf("Moving brk\n");
    //printf("prev: %p & %u\n", tmp->prev, tmp->prev->size);
    if (tmp->prev != NULL)
        master_chuck->last = tmp->prev;
    //printf("mem alloc: %u\n", master_chuck->alloc_mem);
    master_chuck->alloc_mem = (ptrdiff_t) tmp - (ptrdiff_t) master_chuck;
    //printf("New mem alloc: %u & %u\n", master_chuck->alloc_mem, master_chuck->curr_mem);
    if (freed_chuck->last == tmp)
        freed_chuck = NULL;
    //brk(tmp);
}

static void add_node(chunk_t *ptr)
{
    chunk_t *last = freed_chuck->last;
    //unsigned char last_node = 0;

    //if (ptr->next != NULL)
    //    ptr->next->prev = ptr->prev;
    //if (ptr->next == NULL)
    //    last_node = 1;
    //if (ptr->prev != NULL)
    //    ptr->prev->next = ptr->next;
    if (last == NULL)
        last = freed_chuck;
    last->next = ptr;
    last->next->next = NULL;
    last->next->prev = last;
    last->next->free = 1;
    if (ptr->next)
        move_brk();
    unlock_mutex();
}

static void init_free_chuck(chunk_t *ptr)
{
    freed_chuck = ptr;
    freed_chuck->free = 1;
    freed_chuck->last = NULL;
    freed_chuck->next = NULL;
    freed_chuck->prev = NULL;
    unlock_mutex();
}

void free(void *ptr)
{
    //chunk_t *chuck_addr;
    //
    write(1, "b", 1);
    //if (ptr == NULL)
    //    return;
    ////if (master_chuck == NULL)
    ////    raise(SIGSEGV);
    //lock_mutex();
    //chuck_addr = GET_CHUCK_ADDRESS(ptr);
    ////printf("Ptr: %p & %u\n", chuck_addr, chuck_addr->free);
    ////if (!IS_VALID_FREE(chuck_addr) || master_chuck == NULL)
    ////    raise(SIGSEGV);
    //if (freed_chuck == NULL)
    //    return (init_free_chuck(chuck_addr));
    //add_node(chuck_addr);
}
