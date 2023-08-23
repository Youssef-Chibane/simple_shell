#include "simple_shell.h"

/**
 * ft_nulljoin - Creates a new string by copying the content of another string.
 * @s1: The source string to be copied.
 * Return: A pointer to the new string, or NULL on allocation failure.
 */

static char *ft_nulljoin(char *s1)
{
	char *cat;
	int i = 0;

	cat = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (cat == NULL)
		return (NULL);

	while (s1[i])
	{
		cat[i] = s1[i];
		i++;
	}

	cat[i] = '\0';
	return (cat);
}

/**
 * ft_strjoin - Concatenates two strings into a new string.
 * @s1: The first string.
 * @s2: The second string.
 * Return: A pointer to the new concatenated string,
 * or NULL on allocation failure.
 */

char *ft_strjoin(char const *s1, char const *s2)
{
	char *cat;
	int i = 0;
	int j = 0;

	if (s2 == NULL)
		return (ft_nulljoin((char *)s1));

	cat = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (cat == NULL)
		return (NULL);

	while (s1[i] != '\0')
	{
		cat[i] = ((char *)s1)[i];
		i++;
	}

	while (s2[j] != '\0')
	{
		cat[i] = s2[j];
		j++;
		i++;
	}

	cat[i] = '\0';
	return (cat);
}

/**
 * ft_strncmp - Compares two strings up to a specified number of characters.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * @n: The maximum number of characters to compare.
 * Return: An integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
 */

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;

	while ((((unsigned char *)s1)[i] || ((unsigned char *)s2)[i]) && i < n)
	{
		if (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
			i++;
		else if (((unsigned char *)s1)[i] > ((unsigned char *)s2)[i])
			return (1);
		else
			return (-1);
	}

	return (0);
}

/**
 * ft_strdup - Duplicates a string.
 * @s1: The source string to duplicate.
 * Return: A pointer to the newly allocated duplicated string,
 * or NULL on allocation failure.
 */

char *ft_strdup(const char *s1)
{
	int i = 0;
	char *dest;

	if (s1 == NULL)
		return (NULL);

	dest = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);

	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}

/**
 * ft_substr - Extracts a portion of a string.
 * @s: The source string.
 * @start: The starting index of the substring extraction.
 * @len: The maximum length of the extracted substring.
 * Return: A pointer to the newly allocated substring, or NULL on failure.
 */

char *ft_substr(const char *s, unsigned int start, size_t len)
{
	char *sub;
	int i = 0;

	if (start >= ft_strlen(s))
	{
		sub = malloc(1);
		if (sub == NULL)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}

	sub = malloc((len + 1) * sizeof(char));
	if (s == NULL || sub == NULL)
		return (NULL);

	while (s[start] != '\0' && i < (int)len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}

	sub[i] = '\0';
	return (sub);
}
