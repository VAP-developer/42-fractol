/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalons <vicalons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 01:23:15 by vicalons          #+#    #+#             */
/*   Updated: 2024/10/08 13:28:03 by vicalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static size_t	ft_countw(char const *s, char c, int i)
{
	size_t	count;

	count = 0;
	while (s[i] != c && s[i])
	{
		i++;
		count++;
	}
	return (count);
}

static char	**ft_free(char **str, size_t j)
{
	while (j-- > 0)
		free(str[j]);
	free(str);
	return (NULL);
}

static char	**ft_alloc(char **new_s, const char *s, char c)
{
	size_t	iter_s;
	size_t	iter_w;
	size_t	size;

	iter_s = 0;
	iter_w = 0;
	while (s[iter_s])
	{
		if (s[iter_s] != c && s[iter_s])
		{
			size = ft_countw(s, c, iter_s);
			new_s[iter_w] = ft_substr(s, iter_s, size);
			if (!new_s[iter_w])
				return (ft_free(new_s, iter_w));
			iter_s += size;
			iter_w++;
		}
		else
			iter_s++;
	}
	new_s[iter_w] = NULL;
	return (new_s);
}

char	**ft_split(char const *s, char c)
{
	char	**new_s;
	int		size_s;
	int		i;

	i = 0;
	size_s = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			size_s++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	new_s = (char **) malloc(sizeof(char *) * (size_s + 1));
	if (!new_s)
		return (NULL);
	return (ft_alloc(new_s, s, c));
}
