#include <unistd.h>
#include <stdio.h>
#include <string.h>

/**
 *
 *
 *
 */
extern char **environ;

char *_getenv(const char *name);

char *_getenv(const char *name) {
  char *path;
  int i;

  for (i = 0; environ[i] != NULL; i++) {
    if (strncmp(name, environ[i], strlen(name)) == 0) {
      path = environ[i] + strlen(name) + 1;
      break;
    }
  }

  return path;
}


/*int main(void)
{
	char env[] = "PATH";
        char *p;

	p = _getenv(env);
        printf("%s", p);
        return (0);
}*/
