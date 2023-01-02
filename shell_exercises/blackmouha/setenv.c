IF name EXISTS
	IF overwrite == 0
		break;
	ELSE
		SET value TO name
		break;

ELSE
	SET value TO name
	break;

extern char **environ;
"name=value"

int _setenv(const char *name, const char *value, int overwrite);
{
	char *path;
	int i;

	for (i = 0; environ[i] != NULL; i++)
  {
  	if (strncmp(name, environ[i], strlen(name)) == 0)
  	{
  		if (overwrite != 0)
  		{
				path = malloc(sizeof(name) + sizeof(value) + 1);
  			strcpy(path, name);
  			path = strcat(path, "=");
  			path = strcat(path, value);
  			path[(strlen(name) + strlen(value) + 1)] = '\0';
  			return (0);
  		}
  	}
	}

	return path;
}










