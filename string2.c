#include "main.h"
/**
 * _strcat - concatenates 2 strings
 * @dest: input value
 * @src: input value
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int u = 0;
	int j;

	while (dest[i] != '\0')
		i++;
	while (src[u] != '\0')
		u++;
	for (j = 0; j <= u; j++)
	{
		dest[i] = src[j];
		i++;
	}
	return (dest);
}
/**
 * _strcmp - compare string values
 * @s1: input value
 * @s2: input value
 * Return: s1[i] - s2[i]
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/**
 * _strrev - Function that reverse a string
 * @str: string to reverse
 * Return: reversed string
 */
char *_strrev(char *str)
{
	int i;
	int len = 0;
	char c;

	if (!str)
		return (NULL);
	while (str[len] != '\0')
		len++;
	for (i = 0; i < (len / 2); i++)
	{
		c = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = c;
	}
	return (str);
}

/**
 * _itoa - Function that converts any value from int to string
 * @i: Value entered type integer
 * @strout: Standar Out
 * @base: Base to convert values
 * Return: A value type char
 */
char *_itoa(int i, char *strout, int base)
{
	char *str = strout;
	int digit, sign = 0;

	if (i < 0)
	{
		sign = 1;
		i *= -1;
	}
	while (i)
	{
		digit = i % base;
		*str = (digit > 9) ? ('A' + digit - 10) : '0' + digit;
		i = i / base;
		str++;
	}
	if (sign)
		*str++ = '-';
	*str = '\0';
	_strrev(strout);
	return (strout);
}

/**
 * _isdigit - Verify if c is a digit
 * @c: Character to be verified
 * Return: -1 if c is not a digit
 * 0 if is
 */
int _isdigit(char *c)
{
	if (!c || !*c)
		return (0);
	if (!isdigit(*c))
		return (-1);
	return (_isdigit(c + 1));
}
