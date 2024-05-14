/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarunota <jarunota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:22:48 by jarunota          #+#    #+#             */
/*   Updated: 2023/10/10 20:07:20 by jarunota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_count(char const *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (!(*str))
			return (count);
		count++;
		while (*str != c && *str)
			str++;
	}
	return (count);
}

static	char	*ft_extract_word(const char *s, int *i, char c)
{
	int		start;
	char	*word;

	start = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	if (*i > start)
	{
		word = malloc(*i - start + 1);
		if (word)
			ft_strlcpy(word, (char *)s + start, *i - start + 1);
		return (word);
	}
	return (NULL);
}

static	char	**ft_free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	size_t	j;
	char	**arr;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	arr = (char **) malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (!arr)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			arr[j++] = ft_extract_word(s, &i, c);
			if (!arr[j - 1])
				return (ft_free_arr(arr));
		}
	}
	arr[j] = NULL;
	return (arr);
}
