/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:19:24 by pcardin           #+#    #+#             */
/*   Updated: 2024/03/23 15:23:35 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
		{
			if (str[i + 1] >= '0' && str[i + 1] <= '9')
				i++;
			else
				return (1);
		}
		else if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ')
			i++;
		else
			return (1);
	}
	return (0);
}
