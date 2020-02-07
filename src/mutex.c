/*
** EPITECH PROJECT, 2019
** PSU_2019_malloc
** File description:
** TODO: CHANGE DESCRIPTION.
*/

#include <pthread.h>

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void lock_mutex()
{
    pthread_mutex_lock(&mutex);
}

void unlock_mutex()
{
    pthread_mutex_unlock(&mutex);
}
