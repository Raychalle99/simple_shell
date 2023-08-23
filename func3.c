#include "shell.h"
​
​
/**
 * _fork - split
 * @buffr: pointer
 * @cmd: double pointer
 * @argv: argv[0]
 * @round: counter
 *
 * Return: nothing
 */
​
​
void _fork(char *buffr, char **cmd, char **argv, int round)
{
	int y, compl;
	pid_t _pid;
	struct stat st;
	char *str;
​
	str = _itoa(round);
	if (cmd[0] != NULL)
	{
		_pid = fork();
		if (_pid == -1)
		{
			perror("Error");
			free(buffr);
			free(cmd);
			exit(-1);
		}
		if (_pid == 0)
		{
			y = stat(cmd[0], &st);
			if (y != 0)
				cmd[0] = _path(cmd[0]);
			if (execve(cmd[0], cmd, NULL) == -1)
			{
				_p_error(argv[0], str, cmd[0]);
				free(str);
				free(buffr);
				free(cmd);
				exit(-1);
			}
		}
		else if (_pid > 0)
			wait(&compl);
	}
	free(str);
	free(buffr);
	free(cmd);
}
​
​
/**
 * _p_error - print error
 * @argv: argv[0]
 * @str: string
 * @cmd: cmd
 *
 * Return: 0
 */
​
​
int *_p_error(char *argv, char *str, char *cmd)
{
	write(STDERR_FILENO, argv, _str_len(argv));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO,  str, _str_len(str));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _str_len(cmd));
	write(STDERR_FILENO, ": nothing \n", 12);
​
	return (0);
}
​
​
/**
 * _getline - input
 * @void: parameter input
 *
 * Return: buffer
 */
​
​
char *_getline(void)
{
	char *buffr = NULL;
	size_t size = 0;
	ssize_t ops;
	int i = 0;
​
	ops = getline(&buffr, &size, stdin);
	if (!buffr)
	{
		perror("Error Allocating Memory Buffer");
		return (NULL);
	}
	if (ops == 1)
	{
		free(buffr);
		return (NULL);
	}
	else if (ops == EOF)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(buffr);
		exit(0);
	}
	else
	{
		while (buffr[i] == ' ' && buffr[i + 1] == ' ')
			i++;
		if (buffr[i + 1] == '\n')
		{
			free(buffr);
			return (NULL);
		}
	}
	return (buffr);
}
​
​
/**
 * _sig_handler - signal for press ctrl + D
 * @signum: void input
 *
 * Return: nothing
 */
​
​
void _sig_handler(int signum)
{
	(void) signum;
	write(STDOUT_FILENO, "\n:) ", 4);
}
