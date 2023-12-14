#include "custom_shell.h"
#include <signal.hi>

/**
 * handle_interrupt_signal - keeps track if in interactive mode
 * @m: the signal number
 * Return: nothing
 */
void handle_interrupt_signal(int m)
{
	(void)m;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}
