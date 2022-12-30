#include "main.h"

/**
 *main - Entry point
 *
 *
 * Return: Always(0)
 */


int _getline(char **line_ptr, size_t *n, FILE *stream)
{
	int count;

	count = get_count(stream);
	if (count == -1)
		return (-1);
	fseek(stream, (-1 * count), SEEK_CUR);
	*line_ptr = malloc(sizeof(char) * count);
        if (*line_ptr == NULL)
	{
		free(*line_ptr);
		return (-1);
	}
	fread(*line_ptr, 1, count, stream);
	*n = count;
	fseek(stream, count, SEEK_CUR);
	return (count);
}

int get_count(FILE *stream)
{
	char p[1];
	size_t size = 1, nmeb = 1, red;
	int count = 0;

	red = fread(p, size, nmeb, stream);
	if (red < size)
		return (-1);
	count++;
	while (*p != '\n')
	{
	 	red = fread(p, size, nmeb, stream);
		if (red < size)
			return (-1);
	 	count++;
	}
	return (count);
}

/**
int main(int ac __attribute__((unused)), char **av)
{
	char *line_ptr = NULL;
	size_t n = 0;
	int n_read = 0;
	FILE *fp;

	fp = fopen(av[1], "r");
	n_read = _getline(&line_ptr, &n, fp);
	return (0);
}
*/
