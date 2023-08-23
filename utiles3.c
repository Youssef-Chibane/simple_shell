#include "simple_shell.h"

/**
 * ft_strlen - Calculates the length of a string.
 * @s: The input string.
 * Return: The length of the string.
 */

size_t ft_strlen(const char *s)
{
	int i = 0;

	while (s[i])
		i++;

	return (i);
}

/**
 * ft_bzero - Fills a block of memory with zeros.
 * @s: A pointer to the memory block to be filled.
 * @n: The number of bytes to fill with zeros.
 * Return: None.
 */

void ft_bzero(void *s, size_t n)
{
	while (n--)
	{
		*((char *)s + n) = '\0';
	}
}
