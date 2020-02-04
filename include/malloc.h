/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** Main structure for malloc
*/

#ifndef _SRC_MY_MALLOC
#define _SRC_MY_MALLOC

#include <unistd.h>
#include <stddef.h>

void *malloc(size_t size);
void *my_malloc(size_t size);

//typedef struct leaf_s {
//    struct leaf_s *right;
//    struct leaf_s *left;
//    void *ptr;
//} leaf_t;

#define GET_NEXT_CHUNK(c) ((chunk_t *) ((ptrdiff_t) c + (c->size + sizeof(chunk_t))))

typedef struct chuck_s {
    size_t size;
    void *ptr;
    unsigned char free;
    struct chuck_s *right;
    struct chuck_s *left;

    struct chuck_s *next;
} chunk_t;


extern chunk_t *master_chuck;

void *get_free_space(size_t size);
void init_chuck(size_t size);
void *add_main_mem(size_t size);

void add_leaf(chunk_t *chunk, size_t size);

#endif
