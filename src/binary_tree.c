/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** Binary tree for malloc project.
*/

#include <stdio.h>

#include "malloc.h"

void *get_free_space(size_t size)
{
    chunk_t *tmp = master_chuck;

    if (master_chuck == NULL)
        return (NULL);
    while (tmp != NULL && tmp->size < size) {
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return (NULL);
    printf("Find chuck: %p w/ max size of: %zu\n", tmp, size);
    return (update_size(master_chuck, add_leaf(tmp, size,
        GET_SIZE_WO_STRUCT(size))));
}

void *init_chuck(size_t size)
{
    const unsigned int page_size = sysconf(_SC_PAGESIZE);
    size_t real_size = CALCULATE_REAL_SIZE(size);

    master_chuck = sbrk(real_size);
    printf("[MASTER CHUCK] %p -> %zu\n", master_chuck, real_size);
    //printf("Allocated: %zu\n", sizeof(chunk_t) + real_size);
    //printf("Size of chunk: %zu\n", sizeof(chunk_t));
    master_chuck->size = real_size;
    master_chuck->next = NULL;
    master_chuck->left = NULL;
    master_chuck->right = NULL;
    master_chuck->free = 0;
    return (update_size(master_chuck, add_leaf(master_chuck, size,
        GET_SIZE_WO_STRUCT(size))));
    //master_chuck->ptr = ptr;
}

void *add_main_mem(size_t size)
{
    const unsigned int page_size = sysconf(_SC_PAGESIZE);
    chunk_t *tmp = master_chuck;
    size_t real_size = CALCULATE_REAL_SIZE(size);
    //void *ptr;

    printf("add main mem is called w/ %zu\n", real_size);
    //printf("\n\nMaster: %p w/ %p\n", master_chuck, master_chuck->next);
    while (tmp->next != NULL)
        tmp = tmp->next;
    if (tmp == NULL)
        return (NULL);
    printf("Is master? %p & %p\n", master_chuck, tmp);
    //ptr = sbrk(sizeof(chunk_t) + real_size);
    sbrk(real_size);
    //sbrk(sizeof(chunk_t) + real_size);
    //printf("Size for ptr: %zu from %zu\n", sizeof(chunk_t) + real_size, size);
    //printf("Ptr: %p\n", tmp);
    //printf("Size for previous ptr: %zu\n", tmp->size);
    tmp = tmp->next = GET_NEXT_CHUNK(tmp);
    //ptrdiff_t cpy = (ptrdiff_t) tmp;
    //printf("Next set to: %p w/ %p\n", tmp->next, master_chuck->next);
    //tmp = (chunk_t *) ((ptrdiff_t) tmp + (tmp->size + sizeof(chunk_t)));
    //printf("New ptr: %p & %lu\n", tmp, (ptrdiff_t) tmp - cpy);
    //printf("(1) Master next: %p\n", master_chuck->next);
    tmp->size = real_size;
    tmp->next = NULL;
    //printf("(2) Master next: %p\n", master_chuck->next);
    tmp->left = NULL;
    //printf("(3.1) Master next: %p\n", master_chuck->next);
    tmp->right = NULL;
    //printf("(3.2) Master next: %p\n", master_chuck->next);
    tmp->free = 0;
    //printf("(3.3) Master next: %p\n", master_chuck->next);
    //tmp->ptr = NULL; // = ptr;
    //printf("Master at the end: %p -> %p\n",master_chuck, master_chuck->next);
    //printf("Is size even: %zu\n", sizeof(*tmp));
    return (update_size(tmp, add_leaf(tmp, size,
        GET_SIZE_WO_STRUCT(size))));
}
