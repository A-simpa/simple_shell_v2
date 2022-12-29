// use getenv() to get PATH
// split path using _split-word()
// iterate through PATHS
//	concatenate PATH + '/' + filename
//	call stat() on the concatenated result
//	if FOUND
//		return concatenated result

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

char *_getenv(const char *name);
char **split_words(char *str, char del);

int main(int ac __attribute__((unused)), char **av)
{
	char *path;
	char *filename, *c_path;
	char **arr;
	struct stat sb;
	int i = 0;

	filename = av[1];
	path = _getenv("PATH");
	arr = split_words(path, ':');

	while (arr[i])
	{
		c_path = malloc(sizeof(char) * (strlen(filename) + strlen(arr[i]) + 1));
		strcpy(c_path, arr[i]);
		c_path = strcat(c_path, "/");
		c_path = strcat(c_path, filename);
		if (stat(c_path, &sb) == 0)
		{
			printf("FOUND\n");
			free(c_path);
			return (0);
	
		}
		free(c_path);
		i++;
	}
	printf("NOT FOUND\n");
	return 0;
}
