#include "main.h"
/**
 * _strncmp - compare a string with the number of bits
 * @path: first string
 * @match: second string
 * @n: number th bits to be compared
 * Return: return the path if find a match
 */
char *_strncmp(char *path, char *match, size_t n)
{
	while (n && *path && (*path == *match))
	{
		++path;
		++match;
		--n;
	}
	if (n == 0)
	{
		return (path);
	}
	else
	{
		return (NULL);
	}
}
/**
 * _strdup - returns a pointer to a newly allocated space
 * @s: string to be duplicated
 * Return: a pointer to new string
 */
char *_strdup(char *s)
{
	int i;
	char *dup;
	int len;

	if (s == NULL)
	{
		return (NULL);
	}
	len = _strlen(s);
	dup = malloc((sizeof(char) * len) + 1);
	if (dup == NULL)
	{
		return (NULL);
	}
	for (i = 0; s[i] != '\0'; i++)
	{
		dup[i] = s[i];
	}
	dup[i] = '\0';
	return (dup);
}
/**
 * _strlen - function to get the lenght of a string
 * @s: string for be counted
 * Return: length of the string
 */
int _strlen(char *s)
{
	if (!*s || !s)
		return (0);
	return (1 + _strlen(s + 1));
}
/**
 * _strcpy - a function that copies the string pointed to by src
 * @dest: copy to
 * @src: copy from
 * Return: string
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;
	int u = 0;

	while (src[i] != '\0')
		i++;
	while (u <= i)
	{
		dest[u] = src[u];
		u++;
	}
	return (dest);
}
