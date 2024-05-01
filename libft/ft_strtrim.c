/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:31:56 by pcardin           #+#    #+#             */
/*   Updated: 2024/03/26 11:23:10 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;
	char	*s_out;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	s1_len = ft_strlen(s1);
	while (s1_len > i && ft_strchr(set, s1[s1_len - 1]))
		s1_len--;
	s_out = malloc(sizeof(char) * (s1_len - i + 1));
	if (!s_out)
		return (NULL);
	while (i < s1_len)
	{
		s_out[j] = s1[i];
		i++;
		j++;
	}
	s_out[j] = '\0';
	return (s_out);
}

// int main(int argc, char **argv)
// {
// 	if (argc == 3)
// 	{
// 		printf("%s\n", ft_strtrim(argv[1], argv[2]));
// 	}
// 	return (0);
// }