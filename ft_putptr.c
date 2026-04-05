/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opektas <opektas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 00:00:00 by opektas           #+#    #+#             */
/*   Updated: 2026/03/28 00:00:00 by opektas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int	count;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = 0;
	count += ft_putchar('0');
	count += ft_putchar('x');
	count += ft_putnbr_base((unsigned long)ptr,
			"0123456789abcdef", 16);
	return (count);
}
