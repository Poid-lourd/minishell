/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 09:35:51 by pcardin           #+#    #+#             */
/*   Updated: 2023/11/13 20:20:10 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	char_c;

	i = 0;
	char_c = (char) c;
	while (str[i])
	{
		if (str[i] == char_c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == char_c)
		return ((char *)&str[i]);
	return (0);
}
