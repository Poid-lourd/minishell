/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 10:17:39 by pcardin           #+#    #+#             */
/*   Updated: 2023/11/13 20:20:03 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	int		nulterm;
	char	*found_str;
	char	char_c;

	char_c = (char) c;
	i = ft_strlen(str);
	nulterm = i;
	found_str = (char *)str;
	while (i >= 0)
	{
		if (str[i] == char_c)
			return (&found_str[i]);
		i--;
	}
	if (str[nulterm] == char_c)
		return (&found_str[nulterm]);
	return (0);
}
