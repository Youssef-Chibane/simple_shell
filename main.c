#include "simple_shell.h"

/**
 * main - function for the simple shell.
 *
 * @ac: Number of command-line arguments.
 * @av: Array of command-line argument strings.
 * @environ: Array of environment variables.
 * Return: Returns 0 upon successful execution.
 */
int main(int ac, char **av, char **environ)
{
	shell_t data;
	env_t *env;

	(void)av;
	if (ac != 1)
	{
		exit(1);
	}

	env = NULL;
	fill_envlist(&env, environ);
	shell_signals();
	while (1)
	{
		write(1, "shell> ", 7);
		data.read = getline(&data.line, &data.line_len, stdin);
		if (data.read == -1)
		{
			free_list(&env);
			exit(0);
		}
		if (data.line[data.read - 1] == '\n')
		{
			data.line[data.read - 1] = '\0';
		}
		data.cmd = ft_split(data.line, ' ');
		execute_command(&env, data.cmd, environ);
		free_split(data.cmd);
	}
	return (0);
}
