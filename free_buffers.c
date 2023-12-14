#include "custom_shell.h"

/**
 * release_memory_buffers - releases memory for buffers
 * @buf: buffer to be released
 *
 * Return: no return
 */
void release_memory_buffers(char **buf)
{
	int i = 0;

	if (!buf || buf == NULL)
		return;
	while (buf[i])
	{
		free(buf[i]);
		i++;
	}
	free(buf);
}
