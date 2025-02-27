/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalons <vicalons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:42:25 by vicalons          #+#    #+#             */
/*   Updated: 2024/10/08 13:04:27 by vicalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	size;

	if (!s)
		return (0);
	size = ft_strlen(s);
	if (start >= size)
	{
		sub = ft_calloc(1, 1);
		return (sub);
	}
	else if (size - start < len)
		sub = ft_calloc((size - start) + 1, 1);
	else
		sub = ft_calloc(len + 1, 1);
	if (!sub)
		return (0);
	size = 0;
	while (size < len && s[start])
		sub[size++] = s[start++];
	return (sub);
}
