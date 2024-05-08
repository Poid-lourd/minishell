/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:08:39 by pcardin           #+#    #+#             */
/*   Updated: 2024/05/08 15:25:05 by pcardin          ###   ########.fr       */
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
	t_data		*data;
	int 		i;
	// t_sigaction	sa;
	
	(void)argc;
	(void)argv;
	(void)envp;
	// sa.sa_handler = 
	init_struct(&data);
	extract_bin_paths(envp, &data);
	i = 0;
	while (1)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, SIG_IGN);
		// sigaction(SIGINT, );
		input = readline("minishell\xF0\x9F\x90\x9A: ");
		add_history(input);
		parsing(&data, input, envp);
		if (execution(&data, input, envp))
			break ;
		if (input)
			free(input);
	}
	return (0);
}
