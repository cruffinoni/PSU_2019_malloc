/*
** EPITECH PROJECT, 2018
** PSU_2019_malloc
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include "malloc.h"

#include <unistd.h>

void *malloc(size_t size)
{
    const unsigned int MantissaMask = (1<<23) - 1;
    void *ptr;
    (*(float*)&size) = (float) size;
    size = size + MantissaMask & ~MantissaMask;
    size = (size_t) (*(float*)&size);
    malloc_t *new = sbrk(0);
    if ((ptr = sbrk(sizeof(malloc_t) + size)) < 0) {
        return (NULL);
    }
    new->next = NULL;
    new->free = 0;
    new->size = size;
    if (ll == NULL)
        ll = new;
    else
        ll->next = new; // ?
    return (ptr);
}

//
//int main() {
//    a_malloc(5);
//
//    return (0);
//
//}
