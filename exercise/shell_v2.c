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
	pid_t pid1, w;
	ssize_t nread;
	size_t n;

	pid1 = fork();
	if (pid1 == 0)
	{
		printf("I'm  in child process\n");
		printf("%s", p);
		nread = getline(&buf, &n, stdin);
		printf("Buffer : %s", buf);
		if (nread != -1)
		{
			if (buf[nread-1] == '\n')
				buf[nread-1] = '\0';
			argv[0] = buf;
			execve(argv[0], argv, NULL);
		}
	}
	else
	{
		printf("I'm  in parent process\n");
		do
		{
			w = waitpid(pid1, &ws, WUNTRACED | WCONTINUED);
			if (w == -1) {
				perror("waitpid");
				exit(EXIT_FAILURE);
			}

			printf("Something\n");
		} while ( !(WIFSIGNALED(ws)) && (WIFEXITED(ws)) );
	}
	return (EXIT_SUCCESS);
}







































