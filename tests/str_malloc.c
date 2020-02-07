/*
** EPITECH PROJECT, 2018
** my_str_to_array_word.c
** File description:
** Function splits a string into words.
*/

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include "malloc.h"

static int valid_char(char c)
{
    return ((c >= 32 && c <= 126) && c != ' ' && c != ',');
}

static int count_words(char const *str)
{
    int total_count = 0;
    int in_word = 0;

    for (int i = 0; str != NULL && str[i] != '\0'; i++) {
        if (valid_char(str[i]) && !in_word) {
            in_word = 1;
            total_count++;
        }
        if (!valid_char(str[i]))
            in_word = 0;
    }
    return (total_count);
}

static char *malloc_tab(char **tab, char const *str)
{
    int previous_size = 0;
    int j = 0;

    for (int i = 0, quotes = 0; str[i] != '\0'; i++) {
        if (valid_char(str[i]) || quotes) {
            previous_size++;
            quotes = str[i] == '\"' == !quotes;
        }
        else if (previous_size > 0) {
            tab[j++] = my_malloc(sizeof(char) * (previous_size + 1));
            if (tab[j - 1] == NULL)
                return (NULL);
            previous_size = 0;
        }
    }
    if (previous_size > 0)
        tab[j++] = my_malloc(sizeof(char) * (previous_size + 1));
    if (tab[j - 1] == NULL)
        return (NULL);
    tab[j] = NULL;
    return (tab[0]);
}

static void fill_tab(char **tab, char const *str)
{
    int j = 0;
    int k = 0;
    int words = count_words(str);
    bool quotes = false;

    for (int i = 0; str[i] != '\0' && j < words; i++) {
        if (valid_char(str[i]) || quotes) {
            tab[j][k++] = str[i];
            quotes = str[i] == '\"' == !quotes;
        }
        else if (k > 0) {
            tab[j++][k] = '\0';
            k = 0;
        }
    }
    if (words > 0 && k > 0)
        tab[j][k] = '\0';
}

char **my_str_to_word_array(char const *str)
{
    char **tab = NULL;
    int words = count_words(str);

    if (words == 0)
        return (NULL);
    tab = my_malloc(sizeof(char *) * (words + 1));
    if (tab == NULL)
        return (NULL);
    if (malloc_tab(tab, str) == NULL)
        return (NULL);
    fill_tab(tab, str);
    return (tab);
}

#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(int ac, char **av) {
    char **tab = my_str_to_word_array("hello world IAM");
    for (int i = 0; tab[i] != NULL; i++) {
        write(1, tab[i], strlen(tab[i]));
        my_free(tab[i]);
    }
    my_free(tab);
    return (0);
}
