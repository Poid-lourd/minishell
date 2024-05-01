/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:09:45 by pcardin           #+#    #+#             */
/*   Updated: 2023/11/11 16:46:40 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s_out;

	s_out = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!s_out)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s_out[i] = (*f)(i, s[i]);
		i++;
	}
	s_out[i] = '\0';
	return (s_out);
}
