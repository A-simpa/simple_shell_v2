#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int get_count(FILE *stream);
char *_getenv(const char *name);
char **split_words(char *str, char del);
int _getline(char **line_ptr, size_t *n, FILE *stream);

#endif /** MAIN_H */
