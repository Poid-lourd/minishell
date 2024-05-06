
#include "minishell.h"
	
int main(int argc, char **argv)
{
	char *input;
	(void)argc;
	(void)argv;
	
	while (1)
	{
		input = readline("minishell: ");
		if (*input == '\0')
			ft_printf("no input\n");
		else if (!ft_strncmp(input, "exit", ft_strlen(input)))
		{
			ft_printf("exit program\n");
			break ;
		}
		else
		ft_printf("input: %s\n", input);
		free(input);
	}
}
