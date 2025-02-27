/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalons <vicalons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 01:00:33 by vicalons          #+#    #+#             */
/*   Updated: 2024/09/30 10:15:28 by vicalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*s2;

	if (!s)
		return (ft_strdup(""));
	len = ft_strlen(s);
	s2 = (char *) malloc (sizeof(char) * (len + 1));
	if (!s2)
		return (0);
	i = 0;
	while (i < len)
	{
		s2[i] = (*f)(i, s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
