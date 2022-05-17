#include "main.h"

/**
 * accion - Verify if the command is success
 * @path: command to be executed
 * @arguments: arguments of the command
 * @process: number of process of the program
 * Return: The exit status
 */
int accion(char *path, char **arguments, int process)
{
	int i = 0;

	i = fork_hijo(path, arguments, environ);
	if (i == -1)
		error_p(arguments, process);
	return (i);
}

/**
 * error_p - Prints a error message for the command
 * @tokens: command input
 * @process: number of process of the program
 */
void error_p(char **tokens, int process)
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
	perror("");
}

/**
 * fork_hijo - function that creates a child process
 * to execute the given command (camino).
 * @camino: full path of the command to execute.
 * @arguments: command options.
 * @environ: user environment.
 * Return: Success is 0.
 */
int fork_hijo(char *camino, char **arguments, char **environ)
{
	pid_t hijo = 0;
	int status = 0, end = 0;

	hijo = fork();
	if (hijo == -1)
	{
		free(camino);
		return (1);
	}
	if (hijo == 0)
	{
		if (execve(camino, arguments, environ) == -1)
		{
			return (-1);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			end = WEXITSTATUS(status);
		free(arguments);
		free(camino);
	}
	return (end);
}
