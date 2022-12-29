#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#ifndef MAIN_H
#define MAIN_H


int _getline(char **line_ptr, size_t *n, FILE *stream);
int get_count(FILE *stream);

#endif /** MAIN_H */
