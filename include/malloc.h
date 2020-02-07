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
void free(void *ptr);
void my_free(void *ptr);
void *my_malloc(size_t size);

    #define GET_NEXT_CHUNK(c) ((chunk_t *) ((ptrdiff_t) c + \
    (c->size + sizeof(chunk_t))))
    #define GET_SIZE_WO_STRUCT(a) (a - (sizeof(chunk_t) * 2))
    #define GET_DATA_ADDRESS(c) ((chunk_t *) ((ptrdiff_t) c + sizeof(chunk_t)))
    #define CALCULATE_REAL_SIZE(c) ((size / page_size + 1) * page_size)
    #define GET_LEFT_CHUNK_SIZE(c, s) s - sizeof(chunk_t) + \
    ((ptrdiff_t) c->left - (ptrdiff_t) c)
    #define PTR_IN_RANGE(c, t) ((ptrdiff_t) c < t && \
    t < ((ptrdiff_t) c + (ptrdiff_t) c->size))

typedef struct chuck_s {
    size_t size;
    size_t malloc_size;
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
void *update_size(chunk_t *chunk, chunk_t *update);

chunk_t *add_leaf(chunk_t *chunk, size_t size, size_t malloc_size);

#endif
