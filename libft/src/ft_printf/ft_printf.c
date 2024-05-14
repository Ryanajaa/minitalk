/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarunota <jarunota@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 21:05:24 by jarunota          #+#    #+#             */
/*   Updated: 2023/12/26 23:46:15 by jarunota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_validac(va_list *args, char type)
{
	int	print_len;

	print_len = 0;
	if (type == 'c')
		print_len += ft_putchar(va_arg(*args, int));
	if (type == 's')
		print_len += ft_putstr(va_arg(*args, char *));
	if (type == 'p')
		print_len += ft_putptr(va_arg(*args, size_t));
	if (type == 'd' || type == 'i')
		print_len += ft_putnbr(va_arg(*args, int));
	if (type == 'u')
		print_len += ft_putunbr(va_arg(*args, unsigned int));
	if (type == 'x' || type == 'X')
		print_len += ft_puthex(va_arg(*args, unsigned int), type);
	if (type == '%')
		print_len += ft_putchar('%');
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	int		total_len;
	va_list	args;

	total_len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			total_len += ft_validac(&args, *str);
			str++;
		}
		else
		{
			total_len += write(1, str, 1);
			str++;
		}
	}
	va_end(args);
	return (total_len);
}
