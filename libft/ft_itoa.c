/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:48:47 by pcardin           #+#    #+#             */
/*   Updated: 2023/11/24 12:05:52 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long n);
static char	*ft_strreverse(char *str);
static char	*ft_intmin(long n);

char	*ft_itoa(int n)
{
	char	*s_out;
	int		n_len;
	int		i;

	if (n == -2147483648 || n == 0)
		return (ft_intmin(n));
	n_len = ft_intlen((long)n);
	s_out = malloc(sizeof(char) * n_len + 1);
	if (!s_out)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		s_out[i++] = '-';
		n = -n;
	}
	while (n > 0)
	{
		s_out[i] = ((n % 10) + 48);
		n /= 10;
		i++;
	}
	s_out[i] = '\0';
	return (ft_strreverse(s_out));
}

static char	*ft_intmin(long n)
{
	int		i;
	char	*s_out;

	s_out = malloc(sizeof(char) * (ft_intlen(n) + 1));
	s_out[ft_intlen(n)] = '\0';
	if (n == 0)
		s_out[0] = '0';
	if (n != 0)
	{
		n = -n;
		i = 10;
		while (i >= 0)
		{
			if (i == 0)
				s_out[i] = '-';
			else
			{
				s_out[i] = ((n % 10) + 48);
				n /= 10;
			}
			i--;
		}
	}
	return (s_out);
}

static char	*ft_strreverse(char *str)
{
	int		i;
	char	temp;
	int		slen;

	if (str[0] == '-')
		i = 1;
	else
		i = 0;
	slen = ft_strlen(str) - 1;
	temp = 0;
	while (i < slen)
	{
		temp = str[i];
		str[i] = str[slen];
		str[slen] = temp;
		i++;
		slen--;
	}
	return (str);
}

static int	ft_intlen(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

/*
int main()
{
	printf("%s\n", ft_itoa(-2147483648));
	return(0);
}*/