/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalons <vicalons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:29:06 by vicalons          #+#    #+#             */
/*   Updated: 2024/09/26 12:56:19 by vicalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	size;

	size = ft_strlen(s);
	if (!(unsigned char)c)
		return ((char *)&(s[size]));
	while (size--)
	{
		if (s[size] == (unsigned char)c)
			return ((char *)&s[size]);
	}
	return (0);
}
