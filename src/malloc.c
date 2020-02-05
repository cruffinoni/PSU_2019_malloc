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
    void *ptr;

    //const unsigned int page_size = sysconf(_SC_PAGESIZE);
    //void *ptr;
    printf("\nCalling malloc w/ size of %zu\n", size);
    //size += (size / page_size * page_size);
    //printf("Sizes: %zu & %u\n", size, page_size);
    //printf("Malloc: %zu & %zu\n", size / page_size, size);
    size += sizeof(chunk_t);
    printf("Chunk's size: %li\n", sizeof(chunk_t));

    if ((ptr = get_free_space(size)) == NULL) {
        if (master_chuck == NULL) {
            return (init_chuck(size));
        }
        return (add_main_mem(size));
    }
    printf("return real malloc\n");
    printf("[master] %p (%zu) <- %p (%zu) -> %p (%zu)\n", master_chuck->left, master_chuck->left->size,
        master_chuck, master_chuck->size, master_chuck->right, master_chuck->right->size);
    return (ptr);
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
