/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarunota <jarunota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:10:28 by jarunota          #+#    #+#             */
/*   Updated: 2023/10/02 14:21:08 by jarunota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const	char	*s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}