#include "simple_shell.h"

void	int_handler(int num)
{
	(void)num;
	write (2, "\n", 1);
	write(1, "shell> ", 7);
}

void	shell_signals(void)
{
	signal(SIGINT, int_handler);
	signal(SIGQUIT, SIG_IGN);
}
