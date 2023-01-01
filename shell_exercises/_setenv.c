/*
GET `name` `value` `overwrite`
ACCESS the `environ` variable
Check IF name Exist IN environ
		
ELSE
	Declare key_value variable
	Allocate memory for sum of name.len() + value.len() + 2 and assign to `c_string` var
	copy `name` to c_string
	copy "=" too
	copy `value` to c_string
	Delare environ_size
	GET the size of environ and assign to environ_size
	Reallocate the size of environ TO  environ_size + 2
	Assign c_string to environ[environ_size + 1]
	Assign NULL to environ[environ + 2]
	Return 0

FUNC check
	ITERATE through environ
		Split path and assign to arr
		key = arr[0]
		if key == `name` and overwrite == 1
			Allocate space for key_value c_string
			copy `name`, "=" and `value` to c_string
			free  environ[i]
			assign c_string to environ[i]
		else if key == `name`
		return 0
*/
#include "main.h"


int _setenv(const char *name, const char *value, int overwrite)
{
	
	extern char **environ;
	char *c_string = NULL, **new_environ;
	size_t i, environ_size = 0;
	

	i = 0;
	while (environ[i])
	{

		if (strncmp(environ[i], name, strlen(name)) == 0 && overwrite != 0)
		{
			c_string = malloc(sizeof(char) * (strlen(name) + strlen(value) + 2));
			if (!c_string)
				return (-1);
			strcpy(c_string, name);
			strcat(c_string, "=");
			strcat(c_string, value);
			free(environ[i]);
			environ[i] = c_string;
			return (0);
		}
		else if (strncmp(environ[i], name, strlen(name)) == 0)
			return (0);
		i++;
	}

	//check if name exist in environ
	c_string = malloc(sizeof(char) * (strlen(name) + strlen(value) + 2));
	if (!c_string)
		return (-1);
	strcpy(c_string, name);
	c_string = strcat(c_string, "=");		
	c_string = strcat(c_string, value);
	printf("#################################c_string: %s\n", c_string);
	
	//Get size of paths
	i = 0;
	while (environ[i])
	{
		environ_size++;
		i++;
	}

	new_environ = malloc(sizeof(char *) * (environ_size + 2));
	memcpy(new_environ, environ, sizeof(char*) * environ_size);
	new_environ[environ_size] = c_string;
	new_environ[environ_size + 1] = NULL;
	environ = new_environ;

	return 0;
}
