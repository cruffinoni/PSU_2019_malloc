/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <string.h>
#include <errno.h>
#include "malloc.h"

void *calloc(size_t nmemb, size_t size)
{
    size_t total = nmemb * size;
    void *ptr;

    if (total == 0 || ((ptr = malloc(total)) == NULL)) {
        errno = ENOMEM;
        return (NULL);
    }
    return (memset(ptr, 0, total));
}
