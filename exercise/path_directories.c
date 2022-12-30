#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

char *_getenv(const char *name);
char **split_words(char *str, char del);

int main(void)
{
	char *path;
	char **arr;
	int i;

	path = _getenv("PATH");
	arr = split_words(path, ':');

	for (i = 0; arr[i]; i++)
		printf("%s\n", arr[i]);

	return 0;
}
