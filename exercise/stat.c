#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int ac, char **av)
{
	unsigned int i;
	struct stat st;

	if (ac < 2)
	{
		printf("Usage: %s path_to_file ...\n", av[0]);
		return (EXIT_FAILURE);
	}

	i = 1;
	while (av[i])
	{
		printf("%s: ", av[i]);
		if (stat(av[i], &st) == 0)
			printf("Found\n");
		else
			printf("Not found\n");
		i++;
	}
	return (EXIT_SUCCESS);
}

















































