/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opektas <opektas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 23:30:58 by opektas           #+#    #+#             */
/*   Updated: 2026/03/29 02:11:25 by opektas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_dispatch(char type, va_list args)
{
	if (type == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (type == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (type == 'u')
		return (ft_putnbr_base(va_arg(args, unsigned int),
				"0123456789", 10));
	else if (type == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int),
				"0123456789abcdef", 16));
	else if (type == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int),
				"0123456789ABCDEF", 16));
	else if (type == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_dispatch(format[i], args);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
