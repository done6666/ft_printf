/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opektas <opektas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 00:00:00 by opektas           #+#    #+#             */
/*   Updated: 2026/03/28 00:00:00 by opektas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		count += ft_putnbr_base((unsigned long)(-(long)n),
				"0123456789", 10);
	}
	else
		count += ft_putnbr_base((unsigned long)n, "0123456789", 10);
	return (count);
}
