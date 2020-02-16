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
void *my_calloc(size_t nmemb, size_t size);
void *my_realloc(void *ptr, size_t size);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);

#ifndef uint
    typedef unsigned int uint;
#endif

    #define STRUCT_SIZE     (sizeof(chunk_t))
    #define GET_DATA_ADDRESS(c) ((void *) ((void *) c + STRUCT_SIZE))
    //#define GET_CHUCK_ADDRESS(p) ((chunk_t *) ((void *) p - sizeof(chunk_t)))
    #define GET_NEXT_CHUNK(c) ((chunk_t *) ((void *) c + \
    (c->size + STRUCT_SIZE)))
    #define IS_VALID_FREE(c) (c->free != 1 || (c->free != 0 && c->free != 1))
    #define ALIGN_SIZE(s) ((s + (16u - 1u)) & -16u)
    #define MAP_SIZE ALIGN_SIZE((16u * 10u * (uint) sysconf(_SC_PAGESIZE)))

typedef struct chunck_s {
    uint size;
    unsigned char free;

    uint alloc_mem;
    uint curr_mem;
    uint hf_mem;

    struct chunck_s *next;
    struct chunck_s *prev;
    struct chunck_s *last;
} chunk_t; //  __attribute__((packed))

extern chunk_t *master_chuck;
extern chunk_t *freed_chuck;

#endif
