#include "custom_shell.h"
#include <signal.h>

/**
 * execute_builtin - executes builtin functions
 * @command: tokenized commands
 * @line: input read from stdin
 *
 * Return: 1 if executed, 0 if not
 */
int execute_builtin(char **command, char *line)
{
	struct custom_builtins builtins = {"env", "exit"};

	if (custom_strcmp(*command, builtins.env_var) == 0)
	{
		display_env_info();
		return (1);
	}
	else if (custom_strcmp(*command, builtins.exit_cmd) == 0)
	{
		handle_exit_command(command, line);
		return (1);
	}
	return (0);
}
