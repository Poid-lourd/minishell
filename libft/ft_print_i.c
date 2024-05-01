/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:00:30 by pcardin           #+#    #+#             */
/*   Updated: 2024/02/19 11:43:02 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_i(long nbr)
{
	int		i;
	int		len;
	char	buff[64];

	i = 0;
	len = 0;
	if (nbr == 0)
		return (ft_print_c('0'));
	if (nbr < 0)
	{
		nbr *= -1;
		len += ft_print_c('-');
	}
	while (nbr > 0)
	{
		buff[i++] = nbr % 10;
		nbr /= 10;
	}
	while (i > 0)
		len += ft_print_c(buff[--i] + 48);
	return (len);
}
