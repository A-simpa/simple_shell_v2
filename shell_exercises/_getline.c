#include <stdio.h>
#include <stdlib.h>


int _getline(char **lineptr, size_t *len, FILE *stream);


int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	FILE* fp;
	char *lineptr = NULL;
	size_t len = 0;
	int nread = 0;

	fp = fopen(av[1], "rb");

	while ((nread = _getline(&lineptr, &len, fp)))
		printf("lineptr: %s\nnread: %d\n", lineptr, nread);
	
	return (0);
}

int _getline(char **lineptr, size_t *len, FILE *stream)
{
	int i = 0;
	int nread = 0;
	(void)len;
	char ch;
	int n = 0;

	char *hello = malloc(sizeof(char) * 120);
	if (hello == NULL)
		return (-1);

	while ((ch = getc(stream)) != '\n' && ch != EOF)
	{
		nread++;
		if (nread == n)
		{
			hello = realloc(hello, n * 2);
			n = n * 2;
		}
		hello[i] = ch;
		//printf("%c\n", hello[i]);
		i++;

	}	
	hello[i] = '\0';
	*lineptr = hello;
	return (nread);
}
