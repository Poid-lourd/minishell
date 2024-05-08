/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ws.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 09:29:44 by pcardin           #+#    #+#             */
/*   Updated: 2024/05/08 14:35:34 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char sep);
static void	ft_allocate(char **tab, char const *s, char sep);

char	**ft_split_ws(char const *s, char c)
{
	char	**new;

	if (!s)
		return (NULL);
	new = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!new)
		return (NULL);
	ft_allocate(new, s, c);
	return (new);
}

static int	ft_count_words(char const *s, char sep)
{
	int	word_count;

	word_count = 0;
	while (*s)
	{
		while (*s == sep)
			s++;
		if (*s)
			word_count++;
		while (*s && *s != sep)
			s++;
	}
	return (word_count);
}

static void	ft_allocate(char **tab, char const *s, char sep)
{
	char		**tab_p;
	char const	*tmp;

	tmp = s;
	tab_p = tab;
	while (*tmp)
{
		while (*s == sep || *s == ' ')
			s++;
		tmp = s;
		while (*tmp && (*tmp != sep && *tmp != ' '))
			tmp++;
		if (*tmp == sep || tmp > s)
		{
			*tab_p = ft_substr(s, 0, tmp - s);
			s = tmp;
			tab_p++;
		}
	}
	*tab_p = NULL;
}