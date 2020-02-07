/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <string.h>
#include <assert.h>
#include "malloc.h"

#include <stdio.h>

int main(int ac, char **av) {
    char *a = my_malloc(10);
    assert(a != NULL);
    //char *b = my_malloc(20);
    //assert(b != NULL);
    //char *c = my_malloc(5);
    //assert(c != NULL);
    //strcpy(c, "hello world\n");
    //write(2, c, strlen(c));
    //char *d = my_malloc(3990);
    //assert(d != NULL);
    //char *e = my_malloc(6);
    //assert(e != NULL);
    my_free(a);
    return (0);
}
