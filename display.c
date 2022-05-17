#include "main.h"

/**
 * display - Verify the input
 * @first: Number of chars of the input
 * @line: Input
 * @i: Exit status
 */
void display(int first, char *line, int i)
{
	if (first == -1)
	{
		if (errno == EINVAL || errno == ENOMEM)
			perror("./hsh");
		write(STDOUT_FILENO, "\n", 1);
		free(line);
		exit(i);
	}
}

/**
 * display_n - Verify the input for non interactive
 * @first: Number of chars of the input
 * @line: Input
 * @i: Exit estatus
 */
void display_n(int first, char *line, int i)
{
	if (first == -1)
	{
		if (errno == EINVAL || errno == ENOMEM)
			perror("./hsh");
		free(line);
		exit(i);
	}
}
