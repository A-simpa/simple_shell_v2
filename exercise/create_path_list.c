#include "main.h"

/**
 * add_path_end - add a new path from PATH environment variable in a DLL
 * Prototype: path_list_t *add_dnodepath_end(path_list_t **head, const int n);
 * @head: points to the first node;
 * @name: name of the path. For example "/usr/bin"
 *
 * Return: the address of the newly inserted element
 */
path_list_t *add_path_end(path_list_t **head, const char *name)
{
	path_list_t *new_node = malloc(sizeof(*new_node));

	if (new_node == NULL)
		return (NULL);

	new_node->name = malloc(sizeof(name) + 1);
	strcpy(new_node->name, name);
	new_node->next = NULL;
	new_node->prev = NULL;

	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		path_list_t *walk;

		walk = *head;
		while (walk->next != NULL)
			walk = walk->next;

		walk->next = new_node;
		new_node->prev = walk;
	}
	return (new_node);
}

/**
 * print_path_list - prints the DLL for the PATH environment variable
 * Prototype: size_t print_path_list(const path_list_t *h);
 * @h: points to the first element
 *
 * Return: the number of nodes of the DLL
 */
size_t print_path_list(const path_list_t *h)
{
	size_t i;

	if (!h)
		return (0);

	i = 0;
	while (h)
	{
		printf("%s\n", h->name);
		i++;
		h = h->next;
	}

	return (i);
}

/**
 * create_path_list - create a DLL for the PATH environment variable
 *
 * Return: the address of the first node of the DLL
 */
path_list_t *create_path_list(void)
{
	char *path;
	char **arr;
	int i;
	path_list_t *head;

	head = NULL;

	path = _getenv("PATH");
	arr = split_words(path, ':');

	for (i = 0; arr[i]; i++)
		add_path_end(&head, arr[i]);

	return (head);
}


























