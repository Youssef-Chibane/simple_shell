#include "simple_shell.h"

/**
 * split_path - Splits the PATH environment variable into an array of strings.
 * @env: A pointer to the head of the environment linked list.
 * Return: A dynamically allocated array of strings containing the components
 * of the PATH variable. Returns NULL if PATH is not found or if env is empty.
 */

char **split_path(env_t **env)
{
	env_t *temp;
	char **path_split;
	char *path;

	if (!*env)
		return (NULL);

	temp = *env;
	while (temp)
	{
		if (ft_strncmp(temp->key, "PATH", 5) == 0)
		{
			path = ft_strdup(temp->content);
			path_split = ft_split(path, ':');
			free(path);
			return (path_split);
		}
		temp = temp->next;
	}
	return (NULL);
}

/**
 * is_path_exist - Checks if a file or directory exists
 * in the paths from environment.
 * @env: A pointer to the head of the environment linked list.
 * @paths: A pointer to a char pointer array
 * to store the split PATH components.
 * @arg: The file or directory name to search for.
 * Return: 0 if the file/directory is found in PATH,
 * 127 if not found or error.
 */

int is_path_exist(env_t **env, char ***paths)
{
	*paths = split_path(env);

	if (!*paths)
	{
		printf("shell: no such file or directory\n");
		return (127);
	}

	return (0);
}

/**
 * find_path - Finds the full path to an executable file in the given paths.
 * @paths: A pointer to an array of strings containing paths to search in.
 * @args: A pointer to an array of strings containing command and arguments.
 * Return: A dynamically allocated string with the full path to the executable,
 * or NULL if the executable is not found in any of the paths.
 */

char *find_path(char **paths, char **args)
{
	int i;
	char *path;
	char *temp;
	char *temp2;

	i = 0;
	while (paths[i])
	{
		temp = ft_strdup(paths[i]);
		temp2 = ft_strjoin(temp, "/");
		path = ft_strjoin(temp2, args[0]);

		if (access(path, X_OK) == 0)
		{
			free(temp);
			free(temp2);
			return (path);
		}

		free(temp);
		free(temp2);
		free(path);
		i++;
	}

	return (NULL);
}

/**
 * is_path_valid - Checks if a given path is both valid and executable.
 * @path: A pointer to a string containing the path to check.
 * Return: A dynamically allocated string with the valid executable path,
 * or NULL if the path is not valid or not executable.
 */

char *is_path_valid(char *path)
{
	char *result;

	if (!access(path, F_OK) && !access(path, X_OK))
	{
		result = ft_strdup(path);
		return (result);
	}

	return (NULL);
}

/**
 * path_access - Checks if an executable file is
 * accessible within the given paths.
 * @path: A pointer to a string to store the full path to the executable.
 * @path_arr: A pointer to an array of strings containing paths to search in.
 * @args: A pointer to an array of strings containing command and arguments.
 * Return: 0 if the executable is accessible,
 * 127 if not found or not accessible.
 */

int path_access(char **path, char **path_arr, char **args)
{
	*path = find_path(path_arr, args);

	if (!*path)
	{
		return (127);
	}

	return (0);
}