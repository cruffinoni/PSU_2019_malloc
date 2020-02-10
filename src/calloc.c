/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <string.h>
#include "malloc.h"

void *calloc(size_t nmemb, size_t size)
//void *my_calloc(size_t nmemb, size_t size)
{
    size_t total = nmemb * size;
    void *ptr;
    write(1, "d", 1);

    if (total == 0)
        return (NULL);
    if ((ptr = malloc(total)) == NULL)
        return (NULL);
    return (memset(ptr, 0, total));
}
