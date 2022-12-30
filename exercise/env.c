#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


extern char **environ;

int
main(
	int ac __attribute__((unused)),
	char **av __attribute__((unused)),
	char *env[]
)
{
	printf("%p\n", env[0]);
	printf("%p\n", environ[0]);

	return (0);
}
