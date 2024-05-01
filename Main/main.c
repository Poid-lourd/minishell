/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:08:39 by pcardin           #+#    #+#             */
/*   Updated: 2024/05/01 14:03:51 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int main(int argc, char **argv, char **envp)
{
	char	*input;
	char	*args[] = {"usr/bin/clear", NULL};

	(void)argc;
	(void)argv;
	pid_t pid;
	
	while (1)
	{
		input = readline("minishell: ");
		if (*input == '\0')
			ft_printf("no input\n");
		else if (!ft_strncmp(input, "clear", ft_strlen("clear")))
		{
			pid = fork();
			if (pid == 0)
			{
				PL;
				execve("usr/bin/clear", args, envp);
			}
			else if (pid > 0)
				wait(NULL);
		}
		else if (!ft_strncmp(input, "exit", ft_strlen("exit")))
		{
			ft_printf("exit program\n");
			break ;
		}
		else
			ft_printf("input: %s\n", input);
		free(input);
	}
	return (0);
}
