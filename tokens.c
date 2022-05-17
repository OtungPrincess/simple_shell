#include "main.h"
/**
 * tokener - separate the words
 * @str: the string to be separate
 * @delim: the word separator
 * Return: the words separated
 */
char **tokener(char *str, char *delim)
{
	char **command = NULL;
	int words = counter(str), i = 1;

	command = malloc(sizeof(char *) * (words + 1));
	if (!command)
	{
		perror("Error malloc");
		return (NULL);
	}
	command[0] = strtok(str, delim);
	if (command[0] == NULL)
	{
		free_tokens(command);
		return (NULL);
	}
	while (i < (words + 1))
	{
		command[i] = strtok(NULL, delim);
		i++;
	}
	return (command);
}
