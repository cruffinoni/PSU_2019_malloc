/*
** EPITECH PROJECT, 2018
** PSU_2019_malloc
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#ifndef SRC_MALLOC
#define SRC_MALLOC

#include <stddef.h>

void *malloc(size_t size);

typedef struct malloc_s {
    size_t size;
    unsigned char free;
    struct malloc_s *next;
} malloc_t;


malloc_t *ll = NULL;

#endif
