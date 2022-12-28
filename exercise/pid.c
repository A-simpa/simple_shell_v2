#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid, p_pid;

    my_pid = getpid();
    p_pid = getppid();
    printf("%u\n", p_pid);
    printf("%u\n", my_pid);
    return (0);
}
