/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarunota <jarunota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 22:31:44 by jarunota          #+#    #+#             */
/*   Updated: 2023/10/04 21:07:28 by jarunota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_num_size(int n)
{
	int	size;

	if (n < 0)
		n *= -1;
	size = 1;
	while ((n / 10) > 0)
	{
		size++;
		n /= 10;
	}
	return (size);
}

static	int	ft_poweroften(int power)
{
	int	val;

	if (power < 0)
		return (0);
	val = 1;
	while (power--)
		val *= 10;
	return (val);
}

static	int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

static	void	fill_num_str(char *num_str, int n, int num_size)
{
	int	i;

	i = 1;
	while (i <= num_size)
	{
		num_str[i - 1] = (n / ft_poweroften(num_size - i)) + '0';
		n %= ft_poweroften(num_size - i);
		i++;
	}
	num_str[num_size] = '\0';
}

char	*ft_itoa(int n)
{
	char	*result;
	char	*num_str;
	int		num_size;
	int		num;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	num = ft_abs(n);
	num_size = ft_num_size(num);
	num_str = (char *)malloc(sizeof(char) * (num_size + 1));
	if (!num_str)
		return (NULL);
	fill_num_str(num_str, num, num_size);
	num_str[num_size] = '\0';
	if (n < 0)
	{
		result = ft_strjoin("-", num_str);
		free(num_str);
		return (result);
	}
	return (num_str);
}
