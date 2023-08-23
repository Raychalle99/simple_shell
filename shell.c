#include "shell.h"
​
​
/**
 * main - shell
 * @argc: unused
 * @argv: argv[0]
 *
 * Return: 0
 */
​
​
int main(__attribute__((unused)) int argc, char *argv[])
{
	char *buffr = NULL, **cmd;
	int ptr, i, round = 0;
​
	signal(SIGINT, _sig_handler);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, ": ", 3);
		buffr = _getline();
		round++;
		if (!buffr)
			continue;
		ptr = memory_lane(buffr);
		cmd = _str_tok(buffr, ptr);
		_exit1(buffr, cmd);
		i = _env1(buffr, cmd);
		if (i == 0 || cmd == 0)
			continue;
		_fork(buffr, cmd, argv, round);
	}
	return (0);
}
