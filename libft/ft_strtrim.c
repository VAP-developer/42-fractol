/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalons <vicalons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:55:44 by vicalons          #+#    #+#             */
/*   Updated: 2024/09/30 11:16:55 by vicalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*s2;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	j--;
	while (s1[j] && ft_strchr(set, s1[j]))
		j--;
	s2 = ft_substr(s1, i, j - i + 1);
	return (s2);
}
