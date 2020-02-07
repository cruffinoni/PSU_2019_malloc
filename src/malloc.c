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

    if (size == 0)
        return (NULL);
    //const unsigned int page_size = sysconf(_SC_PAGESIZE);
    //void *ptr;
    printf("\nCalling malloc w/ size of %zu\n", size);
    //size += (size / page_size * page_size);
    //printf("Sizes: %zu & %u\n", size, page_size);
    //printf("Malloc: %zu & %zu\n", size / page_size, size);
    size += sizeof(chunk_t) * 2;
    printf("Chunk's size: %li -> Total: %li\n", sizeof(chunk_t), size);

    if ((ptr = get_free_space(size)) == NULL) {
        if (master_chuck == NULL) {
            return (init_chuck(size));
        }
        return (add_main_mem(size));
    }
    printf("return real malloc\n");
    printf("[master] %p (%zu) <- %p (%zu) -> %p (%zu)\n", master_chuck->left, master_chuck->left->malloc_size,
        master_chuck, master_chuck->malloc_size, master_chuck->right, master_chuck->right->malloc_size);
    if (master_chuck->right != NULL)
        printf("[master right] %p (%zu) <- %p (%zu) -> %p (%zu)\n",
            master_chuck->right->left, (master_chuck->right->left != NULL ? master_chuck->right->left->malloc_size : 0),
        master_chuck->right, (master_chuck->right != NULL ? master_chuck->right->malloc_size : 0),
        master_chuck->right->right, (master_chuck->right->right != NULL ? master_chuck->right->right->malloc_size : 0));
    if (master_chuck->left != NULL)
        printf("[master left] %p (%zu) <- %p (%zu) -> %p (%zu)\n",
            master_chuck->left->left, (master_chuck->left->left != NULL ? master_chuck->left->left->malloc_size : 0),
        master_chuck->left, (master_chuck->left != NULL ? master_chuck->left->malloc_size : 0),
        master_chuck->left->right, (master_chuck->left->right != NULL ? master_chuck->left->right->malloc_size : 0));
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
