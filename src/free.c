/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <signal.h>
#include "malloc.h"

void free(void *ptr)
{
    chunk_t *chuck_addr;

    if (ptr == NULL)
        return;
    chuck_addr = (chunk_t *) ((void *) ptr - STRUCT_SIZE);
    if (!IS_VALID_FREE(chuck_addr) || master_chuck == NULL)
        raise(SIGABRT);
    chuck_addr->free = 1;
    if (master_chuck != NULL && master_chuck->hf_mem < chuck_addr->size)
        master_chuck->hf_mem = chuck_addr->size;
}
