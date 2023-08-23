#include "simple_shell.h"

/**
 * fill_envlist - Fills the environment linked list
 * with environment variables.
 * @env: A pointer to a pointer to the head of
 * the environment linked list.
 * @data: A pointer to the shell data structure.
 * @environ: A pointer to an array of strings
 * containing the environment variables.
 * Return: None.
 */

void fill_envlist(env_t **env, char **environ)
{
	int i = 0;

	while (environ[i])
	{
		add_env_list(env, environ[i]);
		i++;
	}
}

