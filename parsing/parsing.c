/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 10:24:51 by pcardin           #+#    #+#             */
/*   Updated: 2024/05/13 10:47:42 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_access_infile(char **argv, t_data **data)
{
	if (access(argv[0], F_OK | R_OK) < 0)
	{
		perror("infile");
		exit(0);
	}
	(*data)->in_path = malloc((ft_strlen(argv[1]) + 1) * sizeof(char));
	if (!(*data)->in_path)
	{
		perror("in_path");
		exit (0);
	}
	ft_strlcpy((*data)->in_path, argv[0], ft_strlen(argv[0]) + 1);
}

void	check_data_access(char **argv, t_data **data)
{
	int		fd;
	int		tbln;

	fd = open(argv[tablen(argv)], O_CREAT | O_WRONLY
			| O_RDONLY | O_TRUNC, 0777);
	if (fd == -1)
	{
		perror("outfile");
		exit(0);
	}
	close(fd);
	check_access_infile(argv, data);
	tbln = tablen(argv);
	(*data)->out_path = malloc((ft_strlen(argv[tbln]) + 1) * sizeof(char));
	if (!(*data)->out_path)
	{
		perror("out_path");
		exit(0);
	}
	ft_strlcpy((*data)->out_path, argv[tbln], ft_strlen(argv[tbln]) + 1);
}

void	parsing(t_data **data, char *input, char **envp)
{
	// int	i;

	(void)envp;
	(*data)->redir = ft_split(input, ',');
	// printf("redir: %s\n", (*data)->redir[0]);
	// printf("redir: %s\n", (*data)->redir[1]);
	// printf("redir: %s\n", (*data)->redir[2]);
	(*data)->cmds = ft_split_ws((*data)->redir[1], '|');
	check_data_access((*data)->redir, data);
	// printf("cmds: %s\n", (*data)->cmds[0]);
	// printf("cmds: %s\n", (*data)->cmds[1]);
}

// infile, ls | wc,outfile
// infile, wc | cat,outfile