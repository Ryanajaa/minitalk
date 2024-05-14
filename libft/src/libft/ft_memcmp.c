/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarunota <jarunota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:21:13 by jarunota          #+#    #+#             */
/*   Updated: 2023/10/02 13:38:44 by jarunota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*p1;
	const char	*p2;
	size_t		i;

	p1 = s1;
	p2 = s2;
	i = 0;
	if (!s1 && !s2)
		return (0);
	while (i < n)
	{
		if (p1[i] != p2[i])
			return ((unsigned char )p1[i] - (unsigned char )p2[i]);
		i++;
	}
	return (0);
}
