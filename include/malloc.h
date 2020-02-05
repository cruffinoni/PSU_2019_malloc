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

#define GET_NEXT_CHUNK(c) ((chunk_t *) ((ptrdiff_t) c + (c->size + sizeof(chunk_t))))
#define GET_SIZE_WO_STRUCT(a) (a - (sizeof(chunk_t)))
#define GET_DATA_ADDRESS(c) ((chunk_t *) ((ptrdiff_t) c + sizeof(chunk_t)))
#define CALCULATE_REAL_SIZE(c) ((size / page_size + 1) * page_size)

typedef struct chuck_s {
    size_t size;
    //void *ptr;
    unsigned char free;
    struct chuck_s *right;
    struct chuck_s *left;

    struct chuck_s *next;
} chunk_t; //  __attribute__((packed))

extern chunk_t *master_chuck;

void *get_free_space(size_t size);
void *init_chuck(size_t size);
void *add_main_mem(size_t size);

void *add_leaf(chunk_t *chunk, size_t size);

#endif
