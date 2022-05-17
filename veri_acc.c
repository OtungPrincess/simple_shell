#include "main.h"

/**
 * ver_access - Verify if the command exists
 * @token: comman to be verified
 * @process: number of process of the command
 * Return: A new command if exists
 * NULL if is not
 */
char *ver_access(char **token, int process)
{
	char *new_command = NULL;
	struct stat st;

	if (stat(token[0], &st) == -1)
	{
		new_command = search_alias(token);
		if (new_command == NULL)
		{
			error_m(token, process);
			free(new_command);
			free(token);
			return (NULL);
		}
	}
	else
		new_command = _strdup(token[0]);
	return (new_command);
}

/**
 * error_m - Prints a error message for the command
 * @tokens: command input
 * @process: number of process of the program
 */
void error_m(char **tokens, int process)
{
	char *num_p = NULL;
	char buffer[1024];

	num_p = _itoa(process, buffer, 10);
	write(1, "./hsh", 5);
	write(1, ": ", 2);
	write(1, num_p, _strlen(num_p));
	write(1, ": ", 2);
	write(1, tokens[0], _strlen(tokens[0]));
	write(1, ": ", 2);
	write(1, "not found\n", 11);
}
