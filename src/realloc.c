/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <string.h>
#include "malloc.h"


#include <stdio.h>

void *realloc(void *ptr, size_t size)
{
    //write(1, "c", 1);
    //printf("Realloc called. Master: %p & last: %p\n",
    //    master_chuck, master_chuck == NULL ? NULL : master_chuck->last);
    void *new_ptr = malloc(size);
    unsigned int old_size;

    if (size == 0 || new_ptr == NULL) {
        //write(1, "RETURNING NULL!", 15);
        //if (new_ptr != NULL)
        //    free(new_ptr);
        return (NULL);
    }
    if (ptr == NULL) {
        //write(1, "(c0)", 4);
        return (new_ptr);
    }
    old_size = ((chunk_t *)((void *)ptr - sizeof(chunk_t)))->size;
    if (size > old_size)
        memcpy(new_ptr, ptr, old_size);
    else
        memcpy(new_ptr, ptr, size);
    //free(ptr);
    //printf("Realloc after. Master: %p & last: %p & ? %p\n",
    //    master_chuck, master_chuck->last, master_chuck->next);
    return (new_ptr);
}
