#include "shell.h"

/**
 * _str_str - search a string
 * @rp: first occurrence of the character
 * @lp: array string
 *
 *Return: 0.
 */

char *_str_str(char *rp, char *lp)
{
	int i;
	int j;
	int k;

	for (i = 0; rp[i] != '\0'; i++)
	{
		j = 0;
		k = i;
		while (rp[k] == lp[j] && lp[j] != '\0')
		{
			j++;
			k++;
		}
		if (lp[j] == '\0')
		{
			return (rp + i);
		}
	}
	return (0);
}

/**
 * _itoa - convert integer to string
 * @number: integer
 *
 *Return: str.
 */

char *_itoa(int number)
{
	unsigned int tmp;
	int div = 1, i = 0;
	char *str;

	str = malloc(sizeof(char) * 11);
	if (str == NULL)
		return (NULL);
	if (number < 0)
	{
		str[i++] = '-';
		tmp = number * -1;
	}
	else
		tmp = number;

	while (tmp / div > 9)
		div *= 10;
	while (div != 0)
	{
		str[i] = (tmp / div) + '0';
		tmp %= div;
		div /= 10;
		i++;
	}
	str[i] = '\0';
	return (str);
}

/**
 * _str_tok - function strtok
 * @buffr: pointer at buffer
 * @ptr: pointer
 *
 * Return: command
 */

char **_str_tok(char *buffr, int ptr)
{
	char **cmd;
	size_t i;
	char *tok;
	char *delim = " \n\t";

	cmd = malloc(sizeof(char *) * ptr);

	if (cmd == NULL)
	{
		free(buffr);
		return (NULL);
	}
	tok = strtok(buffr, delim);

	i = 0;
	while (tok)
	{
		cmd[i] = tok;
		tok = strtok(NULL, delim);
		i++;
	}
	cmd[i] = NULL;
	return (cmd);
}

/**
 * memory_lane - buffer
 * @buffr: buffer
 *
 * Return: round
 */

int memory_lane(char *buffr)
{
	int i, round = 2;
	char *delim = " ";

	for (i = 0; buffr[i] != '\0'; i++)
	{
		if (buffr[i] == delim[0])
			round++;
	}
	return (round);
}

/**
 * memory_lane1 - memory buffer
 * @buffr: buffer
 *
 * Return: int
 */

int memory_lane1(char *buffr)
{
	int i, round = 2;
	char *delim = ":";

	for (i = 0; buffr[i] != '\0'; i++)
	{
		if (buffr[i] == delim[0])
			round++;
	}
	return (round);
}
