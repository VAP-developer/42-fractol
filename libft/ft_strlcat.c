/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalons <vicalons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:04:22 by vicalons          #+#    #+#             */
/*   Updated: 2024/09/26 12:32:18 by vicalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_d;
	size_t	size_s;
	size_t	i;
	size_t	j;

	size_s = ft_strlen(src);
	size_d = ft_strlen(dst);
	if (size_d >= size || size == 0)
		return (size_s + size);
	i = 0;
	j = size_d;
	while (src[i] && i < size - size_d -1)
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (size_s + size_d);
}
