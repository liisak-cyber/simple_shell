#include "custom_shell.h"

/**
 * execute_command - executes commands entered by users
 * @cp: command
 * @cmd: vector array of pointers to commands
 * Return: 0
 */
void execute_command(char *cp, char **cmd)
{
    pid_t child_pid;
    int status;
    char **env = environ;

    child_pid = fork();
    if (child_pid < 0)
        perror(cp);
    if (child_pid == 0)
    {
        execve(cp, cmd, env);
        perror(cp);
        free(cp);
        release_memory_buffers(cmd);
        exit(98);
    }
    else
        wait(&status);
}
