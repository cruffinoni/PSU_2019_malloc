/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <string.h>
#include <errno.h>
#include "malloc.h"

void *realloc(void *ptr, size_t size)
{
    void *new_ptr = malloc(size);
    uint old_size;

    if (size == 0 || new_ptr == NULL) {
        errno = ENOMEM;
        if (new_ptr != NULL)
            free(new_ptr);
        return (NULL);
    }
    if (ptr == NULL)
        return (new_ptr);
    old_size = ((chunk_t *)((void *)ptr - sizeof(chunk_t)))->size;
    if (size > old_size)
        memcpy(new_ptr, ptr, old_size);
    else
        memcpy(new_ptr, ptr, size);
    return (new_ptr);
}
