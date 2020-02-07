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
    write(1, "c", 1);

    if (total == 0)
        return (NULL);
  if (size && (total / size != nmemb))
    {
      errno = ENOMEM;
      return (NULL);
    }
    ptr = malloc(total);
    if (ptr == NULL) {
        return (NULL);
    }
    return (memset(ptr, 0, total));
}
