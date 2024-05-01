/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:56:12 by pcardin           #+#    #+#             */
/*   Updated: 2023/11/24 11:28:20 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*ustr;
	unsigned char	uc;
	size_t			i;

	ustr = (void *) str;
	uc = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (ustr[i] == uc)
			return (&ustr[i]);
		i++;
	}
	return (0);
}
