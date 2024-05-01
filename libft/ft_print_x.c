/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:28:04 by pcardin           #+#    #+#             */
/*   Updated: 2024/02/19 11:42:51 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_x(unsigned long nbr, const char *format)
{
	char	buff[64];
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (nbr > 15)
	{
		buff[i++] = nbr % 16;
		nbr /= 16;
	}
	buff[i] = nbr;
	while (i >= 0)
	{
		if (buff[i] >= 0 && buff[i] <= 9)
			len += ft_print_c(buff[i] + 48);
		else if (buff[i] >= 10 && buff[i] <= 15 && *format == 'x')
			len += ft_print_c(buff[i] + 87);
		else if (buff[i] >= 10 && buff[i] <= 15 && *format == 'X')
			len += ft_print_c(buff[i] + 55);
		i--;
	}
	return (len);
}
