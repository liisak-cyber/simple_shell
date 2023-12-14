#include "custom_shell.h"
#include <signal.hi>

/**
 * retrieve_executable_path - finds the executable path from the global environment
 * Return: NULL if the path is not found, otherwise returns the path.
 */
char *retrieve_executable_path(void)
{
	int x = 0;
	char **env = environ;
	char *path = NULL;

	while (*env)
	{
		if (custom_strncmp(*env, "PATH=", 5) == 0)
		{
			path = *env;
			while (*path && x < 5)
			{
				path++;
				x++;
			}
			return (path);
		}
		env++;
	}
	return (NULL);
}
