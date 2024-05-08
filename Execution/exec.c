/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:37:18 by pcardin           #+#    #+#             */
/*   Updated: 2024/05/08 18:04:31 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	cmd_exec(t_data **data, char **envp, char *cmd, int i)
{
	char *args[] = {cmd, NULL};
	char buffer[1000];

	if ((*data)->cmds[i] == NULL)
	{
		PL;
		read((*data)->fds[0], buffer, 1000);
		printf("%s\n", buffer);
	}
	pipe_err(data);
	fork_err(data, i);
	if ((*data)->pid[i] == 0)
	{
		dup2((*data)->prevpipe, STDIN_FILENO);
		close((*data)->prevpipe);
		close((*data)->fds[0]);
		dup2((*data)->fds[1], STDOUT_FILENO);
		close((*data)->fds[1]);
		// printf("cmd: %s\n", cmd);
		execve(cmd, args, envp);
	}
	else 
	{
		close((*data)->fds[1]);
		close((*data)->prevpipe);
		dup2((*data)->fds[0], (*data)->prevpipe);
		close((*data)->fds[0]);
	}
}

void	cmd_not_found(t_data **data, int i)
{
	(void)data;
	(void)i;
}

int	execution(t_data **data, char *input, char **envp)
{
	int	i;

	i = -1;
	(*data)->prevpipe = 0;
	while (++i < CMDS)
	{
		(*data)->cmds[i] = find_cmd_path(data, i);
		if ((*data)->cmds[i])
			cmd_exec(data, envp, (*data)->cmds[i], i);
		else
			cmd_not_found(data, i);
		if (!ft_strncmp(input, "clear", ft_strlen("clear")))
			ft_printf("\033[H\033[J");
		else if (!ft_strncmp(input, "exit", ft_strlen("exit")))
		{
			ft_printf("exit\n");
			return (1);
		}
	}
	close((*data)->prevpipe);
	return (0);
}
