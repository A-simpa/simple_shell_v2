/**
A simple shell
run commands
input => string separated by space and ended by a newline character

1-) Define the prompt
2-) The programs waits for input
3-) We use execve to execute the command
*/


#include "main.h"

int main(void)
{
	char *p = "#cisfun$ ";
	char *buf, *argv[] = {NULL, NULL};
	int ws;
	pid_t pid1, pid2;
	ssize_t nread;
	size_t n;

	pid1 = fork();
	if (pid1 != 0)
	{
		wait(&ws);
		while ( !(WIFSIGNALED(ws)) && (WIFEXITED(ws)) )
		{
			pid2 = fork();
			if (pid2 != 0)
				wait(&ws);
			else
			{
				printf("%s", p);
				nread = getline(&buf, &n, stdin);
				if (nread != -1)
				{
					if (buf[nread-1] == '\n')
						buf[nread-1] = '\0';
					argv[0] = buf;
					if (execve(argv[0], argv, NULL) == -1)
						perror("Error:");
				}
			}
		}
	}

	else
	{
		printf("%s", p);
		nread = getline(&buf, &n, stdin);
		if (nread != -1)
		{
			if (buf[nread-1] == '\n')
				buf[nread-1] = '\0';
			argv[0] = buf;
			if (execve(argv[0], argv, NULL) == -1)
				perror("Error");
		}
	}

	return (EXIT_SUCCESS);
}







































