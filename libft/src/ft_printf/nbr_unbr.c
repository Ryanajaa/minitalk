/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_unbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarunota <jarunota@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 21:00:45 by jarunota          #+#    #+#             */
/*   Updated: 2023/12/26 21:00:33 by jarunota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_rcs(long int n, int len)
{
	if (n < 0)
	{
		ft_putchar('-');
		len += 1;
		n *= -1;
	}
	if (n < 10)
		len += ft_putchar(n + '0');
	else
	{
		len = ft_putnbr_rcs(n / 10, len);
		len += ft_putchar(n % 10 + '0');
	}
	return (len);
}

int	ft_putnbr(int nb)
{
	return (ft_putnbr_rcs((long int)nb, 0));
}

int	ft_putunbr_rcs(unsigned int n, int len)
{
	if (n < 10)
		len += ft_putchar(n + '0');
	else
	{
		len = ft_putunbr_rcs(n / 10, len);
		len += ft_putchar(n % 10 + '0');
	}
	return (len);
}

int	ft_putunbr(int nb)
{
	return (ft_putunbr_rcs((unsigned int)nb, 0));
}
