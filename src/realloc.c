/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <string.h>
#include "malloc.h"

void *realloc(void *ptr, size_t size)
{
    void *new_ptr = malloc(size);
    write(1, "f", 1);

    lock_mutex();
    write(1, "w", 1);
    if (size == 0 || new_ptr == NULL) {
        unlock_mutex();
        if (new_ptr != NULL)
            free(new_ptr);
        write(1, "z", 1);
        return (NULL);
    }
    write(1, "y", 1);
    if (size < ((chunk_t *)((void *)ptr - sizeof(chunk_t)))->size)
        new_ptr = memcpy(new_ptr, ptr, size);
    else
        new_ptr = memcpy(new_ptr, ptr,
            ((chunk_t *)((void *)ptr - sizeof(chunk_t)))->size);
    write(1, "x", 1);
    unlock_mutex();
    free(ptr);
    return (new_ptr);
}
