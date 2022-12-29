/**
Exercise (fork + wait + execve)
in total six processes => 1 parent and then 5 children
1) declare all need parameters for wait execve
2) fork the parent process => 2 PROCESSES 1 child 1 parent
3) check if the parent is the one running
	if true:
          call wait at this point
          while (wifexited(wstatus) && count < 4)
	  {
		fork();
                if parent:
                  wait();
                else:
                 run execve()
	  }
    else:
       run execve()
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(void)
{
	int ws, i = 0;
	pid_t p1, p2;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	p1 = fork();
	if (p1 != 0)
	{
		wait(&ws);
		while (WIFEXITED(ws) && i < 4)
		{
			p2 = fork();
			if (p2 != 0)
				wait(&ws);
			else
				execve(argv[0], argv, NULL);
			i++;
	  }
	}
	else
	{
		printf("First\n");
		execve(argv[0], argv, NULL);
	}
	return (EXIT_SUCCESS);
}






















