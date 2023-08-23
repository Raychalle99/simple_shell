 #include "shell.h"

/**
 * _str_dup - copy of the string.
 * @str: array
 *
 * Return: string copied.
 */

char *_str_dup(char *str)
{
	int i, j;
	char *fx;

	if (str == NULL)
		return (0);
	i = 0;

	while (*(str + i) != '\0')
		i++;
	fx = malloc(i + 1);
	if (fx == 0)
		return (0);
	for (j = 0; j < i; j++)
		*(fx + j) = *(str + j);
	return (fx);
}

/**
 * _str_cat - concatenate two strings
 * @dest: character to print
 * @src: word to print
 *
 *Return: String concatenate.
 */

char *_str_cat(char *dest, char *src)
{
	int i = 0, c = 0, n = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[c] != '\0')
	{
		c++;
	}
	while (n <= c)
	{
		dest[i] = src[n];
		n++;
		i++;
	}
	return (dest);
}

/**
 * _str_len - length of a string
 * @s: character to print
 *
 *Return: i
 */

int _str_len(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * _str_cmp - String comparate
 * @s1: String One
 * @s2: String Two
 *
 *Return: difference of two string
 */

int _str_cmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

/**
 * _str_cpy - copy a string.
 * @dest: Array Copied
 * @src: - Source of array
 *
 * Return: the string copied.
 */

char *_str_cpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = src[i];
	return (dest);

}
