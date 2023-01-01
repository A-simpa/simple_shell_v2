#include "main.h"

extern char **environ;

int main(void)
{
	int i = 0;
	
	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}

	_setenv("Abdul", "bayero", 1);
	printf("_________________________________________________\n");

	i = 0;
	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}

	printf("__________________________________________________\n");
	_setenv("Abdul", "musa", 1);
	
	i = 0;
	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}

	return (0);
}
