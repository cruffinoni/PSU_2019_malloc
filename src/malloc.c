/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** TODO: CHANGE DESCRIPTION.
*/


#include <stdio.h>
#include <unistd.h>
#include "malloc.h"

chunk_t *master_chuck = NULL;

void *my_malloc(size_t size)
{
    //const unsigned int page_size = sysconf(_SC_PAGESIZE);
    //void *ptr;
    //size += (size / page_size * page_size);
    //printf("Sizes: %zu & %u\n", size, page_size);
    //printf("Malloc: %zu & %zu\n", size / page_size, size);

    if (get_free_space(size) == NULL) {
        if (master_chuck == NULL) {
            master_chuck = sbrk(0);
            init_chuck(size);
            return (master_chuck->ptr);
        }
        return (add_main_mem(size));
    }
    return (malloc(size));
    //malloc_t *new = sbrk(0);
    //if ((ptr = sbrk(sizeof(malloc_t) + size)) < 0) {
    //    return (NULL);
    //}
    //new->next = NULL;
    //new->free = 0;
    //new->size = size;
    //if (ll == NULL)
    //    ll = new;
    //else
    //    ll->next = new; // ?
    //return (ptr);
}
