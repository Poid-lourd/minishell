/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:52:56 by pcardin           #+#    #+#             */
/*   Updated: 2024/02/19 11:43:06 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_p(void *p)
{
	int	len;

	len = 0;
	if (!p)
		return (write(1, "0x0", 3));
	len += write(1, "0x", 2);
	len += ft_print_x((uintptr_t)p, "x");
	return (len);
}
