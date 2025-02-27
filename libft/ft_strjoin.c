/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalons <vicalons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 00:50:05 by vicalons          #+#    #+#             */
/*   Updated: 2024/09/30 07:54:55 by vicalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size1;
	size_t	size2;
	char	*s3;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	s3 = (char *) malloc(sizeof(char) * (size1 + size2 + 1));
	if (!s3)
		return (0);
	ft_strlcpy(s3, s1, size1 + 1);
	ft_strlcat(s3, s2, size1 + size2 + 1);
	return (s3);
}
