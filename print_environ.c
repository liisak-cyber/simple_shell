#include "custom_shell.h"

/**
 * display_environment_info - prints the environment string to stdout
 *
 * Return: 0
 */
void display_environment_info(void)
{
	int x = 0;
	char **env = environ;

	while (env[x])
	{
		write(STDOUT_FILENO, (const void *)env[x], custom_strlen(env[x]));
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}
}
