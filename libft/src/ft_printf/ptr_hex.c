/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarunota <jarunota@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 21:04:40 by jarunota          #+#    #+#             */
/*   Updated: 2023/12/24 01:59:22 by jarunota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr_rcs(size_t num, int len)
{
	if (num >= 16)
	{
		len = ft_putptr_rcs(num / 16, len);
		len = ft_putptr_rcs(num % 16, len);
	}
	else
	{
		if (num < 10)
			len += ft_putchar(num + '0');
		else
			len += ft_putchar(num - 10 + 'a');
	}
	return (len);
}

int	ft_putptr(size_t num)
{
	if (!num)
	{
		write(1, "0x0", 3);
		return (3);
	}
	write(1, "0x", 2);
	return (ft_putptr_rcs(num, 2));
}

int	ft_puthex_rcs(unsigned int num, const char format, int len)
{
	if (num >= 16)
	{
		len = ft_puthex_rcs(num / 16, format, len);
		len = ft_puthex_rcs(num % 16, format, len);
	}
	else
	{
		if (num < 10)
			len += ft_putchar(num + '0');
		else
		{
			if (format == 'x')
				len += ft_putchar(num - 10 + 'a');
			if (format == 'X')
				len += ft_putchar(num - 10 + 'A');
		}
	}
	return (len);
}

int	ft_puthex(unsigned int num, const char format)
{
	return (ft_puthex_rcs(num, format, 0));
}
