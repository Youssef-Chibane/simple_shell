#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

# include <unistd.h>
# include <dirent.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <signal.h>
# include <sys/stat.h>
# include <string.h>
# include <sys/wait.h>

/**
 * struct shell_s - Structure to hold shell-related information.
 *
 * @line: The input line provided to the shell.
 * @cmd: An array of command strings.
 * @line_len: The length of the input line.
 * @read: The number of characters read.
 */

typedef struct	shell_s
{
	char	*line;
	char	**cmd;
	size_t	line_len;
	int		read;
}				shell_t;

/**
 * struct env_s - Structure to hold information about an environment variable.
 *
 * @var: The environment variable in the format "name=value".
 * @key: The name of the environment variable.
 * @content: The value/content of the environment variable.
 * @next: A pointer to the next element in the environment linked list.
 */

typedef struct env_s
{
	char			*var;
	char			*key;
	char			*content;
	struct env_s	*next;
}				env_t;

/**
 * struct s_splitvar - Structure to hold variables
 * for string splitting operations.
 *
 * @i: Integer counter for various purposes.
 * @j: Integer counter for various purposes.
 * @k: Integer counter for various purposes.
 * @len: Length of a substring.
 * @count: Count of elements or substrings.
 * @strings: Array of strings.
 * @ptr: Pointer to a string.
 */

typedef struct s_splitvar
{
	int		i;
	int		j;
	int		k;
	int		len;
	int		count;
	char	**strings;
	char	*ptr;
}				t_splitvar;


void		*ft_calloc(size_t count, size_t size);
char		**ft_split(const char *s, char c);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(const char *s1);
char		*ft_substr(const char *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *s);
void		ft_bzero(void *s, size_t n);
char		**split_path(env_t **env);
int			is_path_exist(env_t **env, char ***paths);
char		*find_path(char **paths, char **args);
char		*is_path_valid(char *path);
int			path_access(char **path, char **path_arr, char **args);
int			execute_command(env_t **env, char **args, char **environ);
char		**equal_split(char *var);
void		free_split(char **split);
void		create_envnode(env_t **head, char *name, char *var, char *env_var);
void		add_env_list(env_t **node, char *var);
void		fill_envlist(env_t **env, char **environ);
void		shell_signals(void);
void		free_list(env_t **list);

#endif
