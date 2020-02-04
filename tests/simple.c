/*
** EPITECH PROJECT, 2018
** PSU_2019_malloc
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <stdio.h>
#include "malloc.h"

int main(int ac, char **av) {
    char *a = malloc(43);
    if (a == NULL)
        return 2;
    a = malloc(43);
    a = malloc(43);
    return (0);
}
