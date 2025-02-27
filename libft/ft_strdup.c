/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalons <vicalons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:21:09 by vicalons          #+#    #+#             */
/*   Updated: 2024/09/29 21:06:46 by vicalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	size_t	i;
	char	*new;

	size = ft_strlen(s1);
	i = 0;
	new = (char *) malloc(size + 1);
	if (!new)
		return (0);
	while (i < size)
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
