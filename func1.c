#include "shell.h"


/**
 * _env1 - environment
 * @buffr: string.
 * @cmd: arguments of buffer.
 *
 * Return: 1 (Success) 0 (Failure)
 */


int _env1(char *buffr, char **cmd)
{
	int i, j, ops;

	if (cmd[1] == NULL)
	{
		ops = _str_cmp(cmd[0], "env");
		if (ops == 0)
		{
			for (i = 0; environ[i] != NULL; i++)
			{
				for (j = 0; environ[i][j] != '\0'; j++)
				{
					write(STDOUT_FILENO, &environ[i][j], 1);
				}
				write(STDOUT_FILENO, "\n", 1);
			}
			free(buffr);
			free(cmd);
			return (0);
		}
		return (1);
	}
	return (1);
}


/**
 * _exit1 - exit
 * @buffr: string.
 * @cmd: arguments of buffr.
 *
 * Return: nothing.
 */


void _exit1(char *buffr, char **cmd)
{
	int ops;

		ops = _str_cmp(cmd[0], "exit");
		if (ops == 0)
		{
			free(buffr);
			free(cmd);
			exit(-1);
		}
}


/**
 * _path - get path
 * @cmd: get command
 *
 * Return: file
 */


char  *_path(char *cmd)
{
	int i, ptr;
	char *delim = ":=", *tk, **foldr, *buffr;
	char *file = NULL;

	i = 0;
	buffr = _get_env("PATH");

	ptr = memory_lane1(buffr);
	foldr = malloc(sizeof(char *) * ptr);

	if (foldr == NULL)
	{
		perror("error allocated memory");
		return (NULL);
	}
	tk = strtok(buffr, delim);

	i = 0;
	while (tk)
	{
		foldr[i] = tk;
		tk = strtok(NULL, delim);
		i++;
	}
	foldr[i] = NULL;
	file = _find(foldr, cmd);
	i = 0;
	free(foldr);
	return (file);
}


/**
 * _find - found directory
 * @foldr: ptr 2 ptr.
 * @cmd: cmd found
 *
 * Return: cmd
 */


char *_find(char **foldr, char *cmd)
{
	int i = 0;
	char *tmp;

	tmp = malloc(sizeof(char) * 100);

	if (tmp == NULL)
		return (NULL);

	while (foldr[i])
	{
		DIR *d;
		struct dirent *dir;

		d = opendir(foldr[i]);

		if (d)
		{
			while ((dir = readdir(d)) != NULL)
			{
				if ((_str_cmp(dir->d_name, cmd)) == 0)
				{
					_str_cpy(tmp, foldr[i]);
					_str_cat(tmp, "/");
					_str_cat(tmp, dir->d_name);
					closedir(d);
					return (tmp);
				}
			}
			closedir(d);
			i++;
		}
	}
	free(tmp);
	return (cmd);
}


/**
 * _get_env - get variables enviroment
 * @ch: parameter in
 *
 * Return: cmd
 */


char *_get_env(char *ch)
{
	int i;
	char *find_path = NULL;
	char *final_path = NULL;
	char *cp_env;

	i = 0;
	while (environ[i] != NULL)
	{
		cp_env = _str_dup(environ[i]);

		if (cp_env == NULL)
		{
			free(cp_env);
			return (NULL);
		}
		find_path = strtok(cp_env, "=");

		if (_str_cmp(find_path, ch) == 0)
		{
			final_path = _str_str(environ[i], "/");
		}
		i++;
	free(cp_env);
	}
	return (final_path);
}


