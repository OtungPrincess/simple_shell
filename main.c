#include "main.h"
/**
 * main - verify if is interactive or no
 * @argc: size of array
 * @argv: array with arguments
 * Return: 0.
 */
int main(int argc, char **argv)
{
	if (isatty(STDIN_FILENO) == 1)
		prompt_interactivo();
	else
		prompt_no_interactivo(argc, argv);
	return (0);
}
