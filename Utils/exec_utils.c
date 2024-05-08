/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:01:11 by pcardin           #+#    #+#             */
/*   Updated: 2024/05/08 18:01:54 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_cmd(char *path)
{
	if (path[ft_strlen(path) - 1] == '/')
		return (FALSE);
	return (TRUE);
}

void	pipe_err(t_data **data)
{
	if (pipe ((*data)->fds) == -1)
	{
		perror("pipe");
		exit(errno);
	}
}

void	fork_err(t_data **data, int i)
{
	(*data)->pid[i] = fork();
	if ((*data)->pid < 0)
	{
		perror("fork");
		exit(errno);
	}
}

char	*find_cmd_path(t_data **data, int i)
{
	char	*path;
	int		accss;
	int		j;

	j = 0;
	while (j < 8)
	{
		path = ft_strjoin2((*data)->paths[j], (*data)->input[i]);
		if (!path)
			return (NULL);
		accss = access(path, X_OK);
		if (accss == 0 && is_cmd(path) == TRUE)
			return (path);
		else
			free(path);
		j++;
	}
	return (NULL);
}
