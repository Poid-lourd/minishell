/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:31:56 by pcardin           #+#    #+#             */
/*   Updated: 2024/04/02 12:03:58 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim2(char const *s1, char const *set)
{
	size_t	s_out_len;
	char	*s_out;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	s_out_len = ft_strlen(s1) - ft_strlen(set);
	s_out = malloc(sizeof(char) * (s_out_len + 1));
	if (!s_out)
		return (NULL);
	while (s1[i] == set[i])
		i++;
	j = 0;
	while (j < s_out_len)
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