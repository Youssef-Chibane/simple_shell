#include "simple_shell.h"

void	free_nodes_content(env_t **node)
{
	if ((*node)->content)
		free ((*node)->content);
	if ((*node)->var)
		free ((*node)->var);
}

void	free_the_whole_node(env_t **node)
{
	free_nodes_content(node);
	if ((*node)->key)
		free((*node)->key);
	free (*node);
}

void	free_list(env_t **list)
{
	if (!*list)
		return ;
	while (*list)
	{
		free_the_whole_node(list);
		*list = (*list)->next;
	}
}
