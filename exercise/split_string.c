#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 *
 *
 *
 *
 */

char **split_string(char *av)
{
	int count = 0, i = 1;
	char **arr, *word,  *carr;

	carr = malloc(sizeof(av));
	strcpy(carr, av);
	word = strtok(av, " \n");
	if (word != NULL)
		count++;
	while ((word = strtok(NULL, " \n")) != NULL)
	{
		count++;
	}
	arr = malloc(sizeof(char *) * ++count);

	word = strtok(carr, " \n");
	if (word != NULL)
		arr[0] = word;

	while ((word = strtok(NULL, " \n")) != NULL)
	{
		arr[i++] = word;
	}
	arr[i] = NULL;

	free(carr);
	return (arr);
}
