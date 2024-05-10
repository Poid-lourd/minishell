/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:55:45 by pcardin           #+#    #+#             */
/*   Updated: 2024/05/10 13:32:37 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_struct(t_data **data)
{
	*data = malloc(sizeof(t_data));
	(*data)->input = NULL;
	(*data)->redir = malloc(4 * sizeof(char));
	(*data)->paths = malloc(8 * sizeof(char));
	(*data)->cmds = malloc(CMDS + 1 * sizeof(char));
	(*data)->fds[0] = 0;
	(*data)->fds[1] = 0;
	(*data)->pid = malloc(CMDS + 1 * sizeof(pid_t));
	(*data)->cmds[CMDS] = NULL;
}

void	extract_bin_paths(char **envp, t_data **data)
{
	int		i;
	char	*str;

	(void)data;
	i = 0;
	str = NULL;
	while (!str)
	{
		str = ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i]));
		i++;
	}
	(*data)->paths = ft_split(str, ':');
	if (!(*data)->paths)
	{
		perror("split");
		exit(0);
	}
}

// void	free_struct(t_data **data)
// {
		
// }