/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:45:47 by pcardin           #+#    #+#             */
/*   Updated: 2024/02/19 15:09:49 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*gnl_strchr(const char *str, int c)
{
	int		i;
	char	*found_str;
	char	char_c;

	i = 0;
	char_c = (char) c;
	found_str = (char *)str;
	while (str[i])
	{
		if (str[i] == char_c)
			return (&found_str[i]);
		i++;
	}
	if (str[i] == char_c)
		return (&found_str[i]);
	return (0);
}

char	*gnl_strjoin(char *s1, char const *s2)
{
	char	*s_out;
	size_t	i;
	size_t	j;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	s_out = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)+ 1));
	if (!s_out)
		return (NULL);
	i = -1;
	j = 0;
	while (s1[++i])
		s_out[i] = s1[i];
	while (s2[j])
		s_out[i++] = s2[j++];
	s_out[i] = '\0';
	return (s_out);
}

char	*gnl_strndup(const char *src, size_t n)
{
	char	*dest;
	size_t	length;
	size_t	i;

	length = ft_strlen(src);
	i = 0;
	if (length > n)
		length = n;
	dest = (char *)malloc(sizeof(char) * (length + 1));
	if (dest == NULL)
		return (NULL);
	while (i < length)
	{
		dest[i] = src[i];
		i++;
	}
	dest[length] = '\0';
	return (dest);
}

char	*gnl_strdup(const char *s1)
{
	char	*dest;
	size_t	i;

	dest = (char *) malloc(ft_strlen(s1) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
