#ifndef MAIN_H
#define MAIN_H

/** C header files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

/** Structures */
typedef struct path_list_n
{
	struct path_list_n *prev;
	struct path_list_n *next;
	char *name;
} path_list_t;

/** Prototypes */
int get_count(FILE *stream);
char *_getenv(const char *name);
char **split_words(char *str, char del);
int _getline(char **line_ptr, size_t *n, FILE *stream);
path_list_t *add_path_end(path_list_t **head, const char *name);
size_t print_path_list(const path_list_t *h);
path_list_t *create_path_list(void);
int _setenv(const char *name, const char *value, int overwrite);

#endif /** MAIN_H */
