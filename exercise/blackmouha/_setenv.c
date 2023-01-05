#include "main.h"

extern char **environ;

/**
 * _setenv  - changes or adds an environment variable for the current process.
 * Prototype: int _setenv(const char *name, const char *value, int overwrite);
 * @name: name of the environment variable
 * @value: value of the environment variable
 * @overwrite: an integer, if 0 updates an existing environment variable.
 *
 * Return: 0 on success, otherwise -1.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	char *kv;
	int i;

	if (!name || !value)
		return (-1);

	for (i = 0; name[i]; i++)
		if (name[i] == '=')
			return (-1);

	for (i = 0; environ[i] != NULL; i++)
  {
  	if (_getenv(name))
  	{
  		if (overwrite != 0)
  		{
				kv = malloc(sizeof(name) + sizeof(value) + 1);
				if (!kv)
					return (-1);
				strcpy(kv, name);
				kv = strcat(kv, "=");
				kv = strcat(kv, value);
				environ[i] = malloc(sizeof(kv));
				strcpy(environ[i], kv);
				return (0);
  		}
  	}
	}

	kv = malloc(sizeof(name) + sizeof(value) + 1);
	if (!kv)
		return (-1);
	strcpy(kv, name);
	kv = strcat(kv, "=");
	kv = strcat(kv, value);

	environ[i] = kv;
	environ[i+1] = NULL;

	return (0);
}

/**
 * main - tests setenv function
 * Prototype: int main(int ac, char *av[], char *ep[]);
 * @ac: number of arguments passed to the program
 * @av: array of arguments passed to the pragram
 * @ep: array of environment variables
 *
 * Return: always 0.
 */

int main(int ac, char *av[], char *envp[] __attribute__((unused)))
{
	int o, i __attribute__((unused));
	char *v, *name, *value;
	if (ac != 4)
	{
		dprintf(2, "Usage ./setenv <ENV_NAME> <ENV_VALUE> <OVERWRITE>\n");
		return (-1);
	}

	name = av[1];
	value = av[2];
	o = atoi(av[3]);

	v = getenv(name);
	if (v)
		printf("%s\n", v);
	else
		printf("undefined\n");

	_setenv(name, value, o);

	v = _getenv(name);
	if (v)
		printf("%s\n", v);
	else
		printf("undefined\n");

	return (0);
}
