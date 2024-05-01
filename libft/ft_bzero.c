/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 08:58:56 by pcardin           #+#    #+#             */
/*   Updated: 2023/11/02 14:49:21 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	char	*c_str;
	size_t	i;

	i = 0;
	c_str = (char *)str;
	while (n > i)
	{
		c_str[i] = 0;
		i++;
	}
}
