#include <stdio.h>

/**
 * main - Arguments
 *
 * Return - Always (0)
 */


int main(int ac __attribute__((unused)), char **av)
{
	char **p;

	p = av;
	while (p != NULL)
	{
		printf("%s", *p);
		p++;
	}
	return (0);
}
