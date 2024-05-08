/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:09:27 by pcardin           #+#    #+#             */
/*   Updated: 2024/05/08 16:12:58 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef PL
#  define PL printf("file:%s line: %d\n", __FILE__, __LINE__)
# endif

# ifndef CMDS
#  define CMDS 2
# endif

# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include "libft/libft.h"

#define TRUE 1
#define	FALSE 2

typedef	struct s_data
{
	char	**input;
	char	**paths;
	char	**cmds;
	
	int		fds[2];
	int		prevpipe;
	pid_t	*pid;
}	t_data;

int		execution(t_data **data, char *input, char **envp);
void	init_struct(t_data **data);
void	parsing(t_data **data, char *input, char **envp);
char	*find_cmd_path(t_data **data, int i);
void	extract_bin_paths(char **envp, t_data **data);

void	pipe_err(t_data **data);
void	fork_err(t_data **data, int i);

// typedef struct s_sigaction
// {
// 	void		(*sa_handler)(int);
// 	sigset_t	sa_mask;
// 	int			sa_flags;
// }	t_sigaction;

#endif