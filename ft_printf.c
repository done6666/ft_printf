/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opektas <opektas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 23:30:58 by opektas           #+#    #+#             */
/*   Updated: 2026/04/19 06:34:17 by opektas          ###   ########.fr       */
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
		return (ft_putnbr_base(va_arg(args, unsigned int), "0123456789", 10));
	else if (type == 'x')
		return (ft_putnbr_base(va_arg(args, unsigned int),
				"0123456789abcdef", 16));
	else if (type == 'X')
		return (ft_putnbr_base(va_arg(args, unsigned int),
				"0123456789ABCDEF", 16));
	else if (type == '%')
		return (ft_putchar('%'));
	return (write(1, "%", 1) + write(1, &type, 1));
}

static int	ft_parse(const char *format, va_list args)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (format[index])
	{
		if (format[index] == '%')
		{
			index++;
			if (!format[index])
				return (-1);
			count += ft_dispatch(format[index], args);
		}
		else
			count += ft_putchar(format[index]);
		index++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	va_start(args, format);
	count = ft_parse(format, args);
	va_end(args);
	return (count);
}
