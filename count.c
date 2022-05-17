#include "main.h"
/**
 * counter - count the words that have the command
 * @string: the command complete
 * Return: the number of words
 */
int counter(char *string)
{
	int a = 0;
	unsigned int iter = 0;

	while (*string)
	{
		if (*string == ' ' || *string == '=' || *string == ':'
			|| *string == '\n' || *string == '\t')
			a = 0;

		else if (a == 0)
		{
			a = 1;
			++iter;
		}
		++string;
	}
	return (iter);
}
