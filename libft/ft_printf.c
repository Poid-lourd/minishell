/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcardin <pcardin@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 11:39:20 by pcardin           #+#    #+#             */
/*   Updated: 2024/02/19 11:42:44 by pcardin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checktype(const char *format, va_list args);
static int	iscorrect(char c);

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	args;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (iscorrect(*format) == 1)
			{
				if (*format == '%')
					len += write(1, "%", 1);
				len += ft_checktype(format, args);
				format++;
			}
		}
		else
			len += write(1, format++, 1);
	}
	va_end(args);
	return (len);
}

static int	ft_checktype(const char *format, va_list args)
{
	int	len;

	len = 0;
	if (*format == 'c')
		len += ft_print_c(va_arg(args, int));
	else if (*format == 's')
		len += ft_print_s(va_arg(args, char *));
	else if (*format == 'd' || *format == 'i')
		len += ft_print_i(va_arg(args, int));
	else if (*format == 'u')
		len += ft_print_i((long)va_arg(args, unsigned int));
	else if (*format == 'p')
		len += ft_print_p(va_arg(args, void *));
	else if (*format == 'x' || *format == 'X')
		len += ft_print_x(va_arg(args, unsigned int), format);
	return (len);
}

static int	iscorrect(char c)
{
	if ((c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i')
		|| (c == 'u' || c == 'x' || c == 'X' || c == '%'))
		return (1);
	else
		return (0);
}
