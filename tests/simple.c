/*
** EPITECH PROJECT, 2019
** my_PSU_2019_malloc
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <stdio.h>
//#include <string.h>
//#include <assert.h>
#include "malloc.h"


int main(int ac, char **av) {
    char *a = my_malloc(10);
    //assert(a != NULL);
    a = my_realloc(a, 6540);
    printf("A done\n");
    char *b = my_malloc(20);
    printf("B done\n");
    ////assert(b != NULL);
    char *c = my_malloc(5);
    //assert(c != NULL);
    my_free(c);
    //c = my_malloc(5);
    ////strcpy(c, "hello world\n");
    ////write(2, c, strlen(c));
    char *d = my_malloc(3990);
    //assert(d != NULL);
    char *e = my_malloc(6);
    //assert(e != NULL);
    char *f = my_malloc(100);
    //assert(f != NULL);
    my_free(a);
    return (0);
}
