#include "simple_shell.h"

/**
 * execute_command - Executes a command with the given arguments.
 * @env: A pointer to the head of the environment linked list.
 * @args: A pointer to an array of strings containing command and arguments.
 * @environ: A pointer to an array of strings containing the environment.
 * Return: 0 on successful execution, -1 on error.
 */

int execute_command(env_t **env, char **args, char **environ)
{
	char **paths;
	char *path;
	pid_t id;
	int	status;

	paths = NULL;
	path = NULL;
	status = 0;
	if (args && args[0] && (args[0][0] == '/' || args[0][0] == '.'))
		path = is_path_valid(args[0]);
	else
	{
		if (is_path_exist(env, &paths))
		{
			perror("./shell");
			free_split(paths);
			return (127);
		}

		if (path_access(&path, paths, args))
		{
			perror("./shell");
			free_split(paths);
			free(path);
			return (127);
		}
	}

	id = fork();
	if (id < 0)
	{
		perror("Fork");
		return (-1);
	}
	else if (id == 0)
	{
		if (execve(path, args, environ) < 0)
		{
			perror("./shell");
			exit(127);
		}
	}
	else
	{
		waitpid(id, &status, 0);
	}
	if (paths)
		free_split(paths);
	if (path)
		free(path);
	return (0);
}

/**
 * equal_split - Splits a string into two parts at the first occurrence of '='.
 * @var: A pointer to the string to be split.
 * Return: A dynamically allocated array of strings containing two parts,
 * or NULL if '=' is not found.
 */

char **equal_split(char *var)
{
	int i;
	char **split;

	i = 0;
	split = malloc(sizeof(char *) * 3);

	while (var[i])
	{
		if (var[i] == '=')
		{
			split[0] = ft_substr(var, 0, i);
			i++;
			split[1] = ft_substr(var, i, ft_strlen(var) + i);
			split[2] = NULL;
			return (split);
		}
		i++;
	}

	free(split);
	return (NULL);
}

/**
 * free_split - Frees memory allocated for an array
 * of strings and the array itself.
 * @split: A pointer to the array of strings to be freed.
 * Return: None.
 */

void free_split(char **split)
{
	int i = 0;

	while (split[i])
		free(split[i++]);
	free(split);
}

/**
 * create_envnode - Creates a new node and adds it
 * to the end of the environment linked list.
 * @head: A pointer to the head of the environment linked list.
 * @name: The name of the environment variable.
 * @var: The value of the environment variable.
 * @env_var: The combined name=value representation
 * of the environment variable.
 * Return: None.
 */

void create_envnode(env_t **head, char *name, char *var, char *env_var)
{
	env_t *new_node;
	env_t *last;

	last = NULL;
	new_node = malloc(sizeof(env_t));
	if (!new_node)
		return;

	new_node->var = ft_strdup(env_var);
	new_node->key = ft_strdup(name);
	new_node->content = ft_strdup(var);
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
		return;
	}

	last = *head;
	while (last->next != NULL)
		last = last->next;

	last->next = new_node;
}

/**
 * add_env_list - Adds a new environment variable node to the linked list.
 * @node: A pointer to a pointer to the head of the environment linked list.
 * @var: The environment variable string in the format "name=value".
 * Return: None.
 */

void add_env_list(env_t **node, char *var)
{
	char **split;

	split = equal_split(var);

	if (!split)
		return;

	create_envnode(node, split[0], split[1], var);
	free_split(split);
}
