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
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);

#ifndef uint
    typedef unsigned int uint;
#endif
#ifndef ullong
    typedef unsigned long long ullong;
#endif

    #define STRUCT_SIZE     (sizeof(chunk_t))
    #define GET_DATA_ADDRESS(c) ((void *) ((void *) c + STRUCT_SIZE))
    #define REAL_SIZE(s) ((s + STRUCT_SIZE + master_chuck->curr_mem))
    #define GET_NEXT_CHUNK(c) ((chunk_t *) ((void *) c->addr + (c->size)))
    #define IS_VALID_FREE(c) (c->free != 1 || (c->free != 0 && c->free != 1))
    #define ALIGN_SIZE(s) ((s + (16u - 1u)) & ~(16u - 1u))
    #define MAP_SIZE ALIGN_SIZE((16u * 10u * (uint) sysconf(_SC_PAGESIZE)))

typedef struct chunck_s {
    uint size;
    unsigned char free;
    void *addr;

    ullong alloc_mem;
    ullong curr_mem;
    ullong hf_mem;

    struct chunck_s *next;
    struct chunck_s *prev;
    struct chunck_s *last;
} chunk_t; //  __attribute__((packed))

extern chunk_t *master_chuck;
extern chunk_t *freed_chuck;

#endif
