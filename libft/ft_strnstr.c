/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalons <vicalons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:37:31 by vicalons          #+#    #+#             */
/*   Updated: 2024/09/30 00:38:58 by vicalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	n;

	if (*little == 0)
		return ((char *)big);
	n = ft_strlen(little);
	while (*big && n <= len)
	{
		if (*big == *little && ft_strncmp(big, little, n) == 0)
			return ((char *) big);
		++big;
		--len;
	}
	return (0);
}
