/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarunota <jarunota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 19:16:18 by jarunota          #+#    #+#             */
/*   Updated: 2023/10/10 19:46:47 by jarunota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		dst_len;
	size_t		res_len;
	size_t		i;

	dst_len = 0;
	if (dst)
		dst_len = ft_strlen(dst);
	res_len = dst_len + ft_strlen(src);
	i = 0;
	if (dstsize <= dst_len)
		return (dstsize + ft_strlen(src));
	if (dstsize)
	{
		while (dst_len + i < dstsize - 1 && src[i])
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
	}
	return (res_len);
}
