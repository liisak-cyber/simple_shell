#include "custom_shell.h"

/**
 * user_prompt - prints $ to let the user know the program is
 * ready to take their input
 * prints the prompt if the shell is in interactive mode
 * Return: no return
 */
void user_prompt(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		operational_flags.is_interactive_mode = true;
	if (operational_flags.is_interactive_mode)
		write(STDERR_FILENO, "$ ", 2);
}
