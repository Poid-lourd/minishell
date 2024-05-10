/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:37:18 by pcardin           #+#    #+#             */
/*   Updated: 2024/05/10 16:39:50 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	redirect_output(t_data **data)
{
	int		fd_out;

	fd_out = open((*data)->out_path, O_WRONLY | O_RDONLY | O_TRUNC, 0);
	if (fd_out == -1)
	{
		perror("outfile");
		exit(0);
	}
	PL;
	dup2(fd_out, STDOUT_FILENO);
}

void	pipe_handling(t_data **data, int i)
{
	dup2((*data)->prevpipe, STDIN_FILENO);
	close((*data)->prevpipe);
	close((*data)->fds[0]);
	if ((*data)->cmds[i + 1] == NULL)
		dup2((*data)->fds[1], STDOUT_FILENO);
	else
		redirect_output(data);
	close((*data)->fds[1]);
}

void	cmd_exec(t_data **data, char **envp, char *path, int i)
{
	char	*args[] = {(*data)->cmds[i], NULL};
	pid_t	pid;

	pipe_err(data);
	pid = fork();
	check_fork_err(pid);
	if (pid == 0)
	{
		pipe_handling(data, i);
		execve(path, args, envp);
	}
	else
	{
		close((*data)->fds[1]);
		close((*data)->prevpipe);
		dup2((*data)->fds[0], (*data)->prevpipe);
		close((*data)->fds[0]);
	}
}

// void	cmd_not_found(t_data **data, int i)
// {
	// (void)i;
	// ft_printf("minishell: %s: command not found\n", (*data)->cmds[i]);
	// close((*data)->prevpipe);
	// (*data)->prevpipe = dup((*data)->fds[0]);
	// close((*data)->fds[1]);
	// close((*data)->fds[0]);
// } infile, wc | cat,outfile

int	execution(char *input, t_data **data, char **envp)
{
	int		i;
	char	*path;

	i = -1;
	(*data)->prevpipe = open((*data)->in_path, O_RDONLY);
	while (++i < CMDS)
	{
		path = find_cmd_path(data, i);
		// if ((*data)->cmds[i] == NULL)
			// cmd_not_found(data, i);
		printf("path: %s\n", path);
		if (path)
			cmd_exec(data, envp, path, i);
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
