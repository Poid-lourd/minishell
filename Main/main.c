/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:08:39 by pcardin           #+#    #+#             */
/*   Updated: 2024/05/06 10:55:34 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// void	sigint_handler(int signum)
// {
// 	ft_printf("\033[H");
// }

int main(int argc, char **argv, char **envp)
{
	char		*input;
	// t_sigaction	sa;

	(void)argv;
	(void)argc;
	(void)envp;
	// sa.sa_handler = 

	while (1)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, SIG_IGN);
		// sigaction(SIGINT, );
		input = readline("minishell\xF0\x9F\x90\x9A: ");
		if (*input == '\0')
			ft_printf("no input\n");
		else if (!ft_strncmp(input, "clear", ft_strlen("clear")))
		{
			ft_printf("\033[H\033[J");
		}
		else if (!ft_strncmp(input, "exit", ft_strlen("exit")))
		{
			ft_printf("exit\n");
			break ;
		}
		else
			ft_printf("input: %s\n", input);
		free(input);
	}
	return (0);
}
