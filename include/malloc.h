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
void *my_realloc(void *ptr, size_t size);
void *calloc(size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);


#ifndef __X86_64__
    #define SYS_ALIGN (16)
#else
    #define SYS_ALIGN (8)
#endif

    #define GET_DATA_ADDRESS(c) ((void *) ((void *) c + sizeof(chunk_t)))
    #define GET_CHUCK_ADDRESS(p) ((chunk_t *) ((ptrdiff_t) p - sizeof(chunk_t)))
    #define GET_NEXT_CHUNK(c) ((chunk_t *) ((void *) c + \
    (c->size + sizeof(chunk_t))))
    #define IS_VALID_FREE(c) (c->free != 1 || (c->free != 0 && c->free != 1))
    #define ALIGN_SIZE(s) ((s + (SYS_ALIGN - 1)) & -SYS_ALIGN)
    #define MAP_SIZE ALIGN_SIZE((SYS_ALIGN * 10 * sysconf(_SC_PAGESIZE)))

typedef struct chunck_s {
    unsigned int size;
    //unsigned int malloc_size;
    //void *ptr;
    unsigned char free;
    //struct chuck_s *right;
    //struct chuck_s *left;

    unsigned int alloc_mem;
    unsigned int curr_mem;

    struct chunck_s *next;
    struct chunck_s *prev;
    struct chunck_s *last;
} chunk_t; //  __attribute__((packed))

extern chunk_t *master_chuck;
extern chunk_t *freed_chuck;

void lock_mutex();
void unlock_mutex();

#endif
