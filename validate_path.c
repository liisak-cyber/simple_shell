#include "custom_shell.h"
#include <signal.h>

/**
* run_custom_shell - carries out the read, execute then print output loop
* @ac: argument count
* @av: argument vector
* @envp: environment vector
*
* Return: 0
*/
int run_custom_shell(int ac, char **av, char *envp[])
{
	char *line = NULL, *pathcommand = NULL, *path = NULL;
	size_t bufsize = 0;
	ssize_t linesize = 0;
	char **command = NULL, **paths = NULL;
	(void)envp, (void)av;
	if (ac < 1)
		return (-1);
	signal(SIGINT, handle_signal);
	while (1)
	{
		release_memory_buffers(command);
		release_memory_buffers(paths);
		free(pathcommand);
		user_prompt();
		linesize = getline(&line, &bufsize, stdin);
		if (linesize < 0)
			break;
		program_information.ln_count++;
		if (line[linesize - 1] == '\n')
			line[linesize - 1] = '\0';
		command = command_tokenizer(line);
		if (command == NULL || *command == NULL || **command == '\0')
			continue;
		if (command_checker(command, line))
			continue;
		path = locate_executable();
		paths = command_tokenizer(path);
		pathcommand = validate_path(paths, command[0]);
		if (!pathcommand)
			perror(av[0]);
		else
			execute_command(pathcommand, command);
	}
	if (linesize < 0 && operational_flags.is_interactive_mode)
		write(STDERR_FILENO, "\n", 1);
	free(line);
	return (0);
}
