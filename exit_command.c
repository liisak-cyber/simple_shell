#include "custom_shell.h"

/**
 * handle_exit_command - handles the exit command
 * @command: tokenized command
 * @line: input read from stdin
 *
 * Return: no return
 */
void handle_exit_command(char **command, char *line)
{
	free(line);
	release_memory_buffers(command);
	exit(0);
}
