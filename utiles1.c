#include "simple_shell.h"

/**
 * ft_calloc - Allocates and initializes memory for an array of elements.
 * @count: The number of elements to allocate memory for.
 * @size: The size of each element in bytes.
 * Return: A pointer to the allocated and initialized memory,
 * or NULL if memory allocation fails.
 */
void *ft_calloc(size_t count, size_t size)
{
	void *ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);

	ft_bzero(ptr, count * size);
	return (ptr);
}

/**
 * wordcount - Counts the number of words separated by a specific character.
 * @s: The string to count words in.
 * @c: The character used as a delimiter between words.
 * Return: The number of words found in the string.
 */

static int wordcount(char *s, char c)
{
	int i = 0;
	int count = 0;

	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;

		if (s[i] != '\0')
			count++;

		while (s[i] != c && s[i] != '\0')
			i++;
	}

	return (count);
}

/**
 * wordlen - Calculates the length of a word delimited by a specific character.
 * @s: The string containing the word.
 * @c: The character used as a delimiter between words.
 * Return: The length of the word.
 */

static int wordlen(char *s, char c)
{
	int i = 0;
	int len = 0;

	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;

		while (s[i] != c && s[i] != '\0')
		{
			i++;
			len++;

			if (s[i] == c)
				return (len);
		}
	}

	return (len);
}

/**
 * one_element - Creates an array containing a single element from a string.
 * @s: The string to be stored as a single element in the array.
 * @str: A pointer to an array of strings to store the single element.
 * Return: A pointer to the array containing the single element.
 */

static char **one_element(char *s, char **str)
{
	int i = 0;
	int j = 0;

	str[i] = ft_calloc((ft_strlen(s) + 1), sizeof(char));

	while ((size_t) j < ft_strlen(s))
	{
		str[i][j] = s[j];
		j++;
	}

	return (str);
}

/**
 * ft_split - Splits a string into an array of substrings based on a delimiter.
 * @s: The string to be split.
 * @c: The delimiter character.
 * Return: A dynamically allocated array of strings containing the substrings,
 * or NULL on allocation failure.
 */

char **ft_split(const char *s, char c)
{
	t_splitvar var;

	var.i = 0;
	var.k = 0;
	var.strings = ft_calloc((wordcount((char *)s, c) + 1), sizeof(char *));

	if (wordcount((char *)s, c) == 1)
		return (one_element((char *)s, var.strings));

	if (var.strings == NULL)
		return (NULL);

	while (s[var.i] != '\0')
	{
		while (s[var.i] == c)
			var.i++;

		if (s[var.i] == '\0')
			break;

		var.len = wordlen((char *)&s[var.i], c);
		var.strings[var.k] = ft_calloc((var.len + 1), sizeof(char));

		if (var.strings[var.k] == NULL)
			return (NULL);

		var.j = 0;
		while (s[var.i] != c && s[var.i] != '\0')
			var.strings[var.k][var.j++] = s[var.i++];

		var.k++;
	}

	return (var.strings);
}
