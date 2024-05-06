/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:09:27 by pcardin           #+#    #+#             */
/*   Updated: 2024/05/06 10:55:00 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef PL
#  define PL printf("file:%s line: %d\n", __FILE__, __LINE__)
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

// typedef struct s_sigaction
// {
// 	void		(*sa_handler)(int);
// 	sigset_t	sa_mask;
// 	int			sa_flags;
// }	t_sigaction;

#endif