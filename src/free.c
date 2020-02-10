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
    chunk_t *tmp = master_chuck->last;

    //printf("Moving brk\n");
    if (tmp->prev != NULL)
        master_chuck->last = tmp->prev;
    master_chuck->alloc_mem = (ptrdiff_t) tmp - (ptrdiff_t) master_chuck;
    if (freed_chuck->last == tmp)
        freed_chuck = NULL;
}

static void add_node(chunk_t *ptr)
{
    chunk_t *last = freed_chuck->last;
    chunk_t *last_next;

    //printf("Passing here twice\n");
    if (master_chuck->last == ptr)
        master_chuck->last = master_chuck->last->prev;
    else if (master_chuck == ptr) {
        if (master_chuck->next != NULL)
            master_chuck->next->last = master_chuck->last;
        master_chuck = master_chuck->next;
    }
    if (last == NULL)
        last = freed_chuck;
    last_next = last->next;
    if (ptr->prev != NULL)
        ptr->prev->next = ptr->next;
    if (ptr->next != NULL)
        ptr->next->prev = ptr->prev;
    last->next = ptr;
    last->next->next = NULL;
    last->next->prev = last;
    last->next->free = 1;
    if (last_next == NULL)
        move_brk();
    unlock_mutex();
}

static void init_free_chuck(chunk_t *ptr)
{
    //printf("master & curr: %p & %p\n", master_chuck->last, ptr);
    //printf("Last: %p & previous: %p\n", master_chuck->last, master_chuck->last->prev);
    //printf("Master thing: %p & %p\n", master_chuck, master_chuck->next);
    if (master_chuck->last == ptr)
        master_chuck->last = master_chuck->last->prev;
    else if (master_chuck == ptr) {
        if (master_chuck->next != NULL)
            master_chuck->next->last = master_chuck->last;
        master_chuck = master_chuck->next;
    }
    //printf("Last(?): %p\n", master_chuck->last);
    if (ptr->prev != NULL)
        ptr->prev->next = ptr->next;
    if (ptr->next != NULL)
        ptr->next->prev = ptr->prev;
    freed_chuck = ptr;
    freed_chuck->free = 1;
    freed_chuck->last = NULL;
    freed_chuck->next = NULL;
    freed_chuck->prev = NULL;
    unlock_mutex();
}

//void my_free(void *ptr)
void free(void *ptr)
{
    //chunk_t *chuck_addr;
    //
    write(1, "b", 1);
    //if (ptr == NULL)
    //    return;
    //if (master_chuck == NULL)
    //    raise(SIGSEGV);
    //lock_mutex();
    //chuck_addr = GET_CHUCK_ADDRESS(ptr);
    //if (!IS_VALID_FREE(chuck_addr) || master_chuck == NULL)
    //    raise(SIGSEGV);
    //if (freed_chuck == NULL)
    //    return (init_free_chuck(chuck_addr));
    //add_node(chuck_addr);
}
