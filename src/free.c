/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <signal.h>
#include "malloc.h"


#include <stdio.h>

static void move_brk()
{
    chunk_t *last = master_chuck->last;

    if (last->prev != NULL)
        master_chuck->last = last->prev;
    master_chuck->alloc_mem = (ptrdiff_t) last - (ptrdiff_t) master_chuck;
    if (freed_chuck->last == last)
        freed_chuck = NULL;
    brk(last);
}

static void move_ptr(chunk_t *ptr)
{
    if (master_chuck == ptr) {
        //write(1, "b1", 2);
        if (master_chuck->next != NULL)
            master_chuck->next->last = master_chuck->last;
        master_chuck = master_chuck->next;
    } else if (master_chuck != NULL && master_chuck->last == ptr) {
        //write(1, "b0", 2);
        master_chuck->last = master_chuck->last->prev;
    }
    if (ptr->prev != NULL)
        ptr->prev->next = ptr->next;
    if (ptr->next != NULL)
        ptr->next->prev = ptr->prev;
}

static void add_node(chunk_t *ptr)
{
    chunk_t *last = freed_chuck->last;

    move_ptr(ptr);
    //write(1, "c0", 2);
    last->next = ptr;
    last->next->next = NULL;
    last->next->prev = last;
    last->next->free = 1;
    freed_chuck->last = last->next;
}

static void init_free_chuck(chunk_t *ptr)
{
    move_ptr(ptr);
    //write(1, "d0", 2);
    freed_chuck = ptr;
    freed_chuck->free = 1;
    freed_chuck->last = freed_chuck;
    freed_chuck->next = NULL;
    freed_chuck->prev = NULL;
}

void free(void *ptr)
{
    chunk_t *chuck_addr;

    //write(1, "a0", 2);
    if (ptr == NULL)
        return;
    chuck_addr = (chunk_t *) ((void *) ptr - STRUCT_SIZE);
    //write(1, "a1", 2);
    if (!IS_VALID_FREE(chuck_addr) || master_chuck == NULL)
        raise(SIGABRT);
    chuck_addr->free = 1;
    if (freed_chuck == NULL)
        return (init_free_chuck(chuck_addr));
    //add_node(chuck_addr);
}
