/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <string.h>
#include <assert.h>
#include "malloc.h"

int main(int ac, char **av) {
    char *a = my_malloc(10);
    assert(a != NULL);
    char *b = my_malloc(20);
    assert(b != NULL);
    char *c = my_malloc(30);
    assert(c != NULL);
    strcpy(c, "hello world\n");
    write(1, c, strlen(c));
    //free(a);
    return (0);
}
