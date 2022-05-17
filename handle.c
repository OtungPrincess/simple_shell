#include "main.h"

/**
 * handler - Continue with Ctrl + C
 * @signal: Signal input
 */
void handler(int signal)
{
	(void)signal;

	write(1, "\n", 1);
	write(STDOUT_FILENO, "Shell$ ", 7);
}
