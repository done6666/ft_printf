/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opektas <opektas@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 00:00:00 by opektas           #+#    #+#             */
/*   Updated: 2026/03/28 00:00:00 by opektas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long n, char *base, int base_len)
{
	int	count;

	count = 0;
	if (n >= (unsigned long)base_len)
		count += ft_putnbr_base(n / base_len, base, base_len);
	count += ft_putchar(base[n % base_len]);
	return (count);
}
