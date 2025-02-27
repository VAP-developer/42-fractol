/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalons <vicalons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:04:52 by vicalons          #+#    #+#             */
/*   Updated: 2024/11/05 12:07:00 by vicalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* FUNC CALLOC:
 * 	initialized dynnamic memory
 * VAR
 * 	ptr: (char) var that we allocate memory
 * 	tmp: (char) temporal var temporal that we iterate
 * CODE
 * 	1. allocate memory in ptr
 * 	2. test ptr
 * 	3. tmp = ptr
 * 	4. iterate *tmp++ = '\0'
 * RETURN
 * 	ptr
 * EXAMPLE
 * 	ft_calloc(3, sizeof(char)) --> ***
 */
char	*ft_calloc(size_t n, size_t type)
{
	char	*ptr;
	char	*tmp;

	ptr = (char *) malloc(n * type);
	if (!ptr)
		return (NULL);
	tmp = ptr;
	while (n--)
		*tmp++ = '\0';
	return (ptr);
}

/* FUNC STRLEN
 * 	count char in str
 * VAR
 * 	nbr_chr: (size_t) number of char int the str
 * CODE
 * 	1. nbr_chr = 0
 * 	2. iter s adn nbr_chr++
 * RETURN
 * 	nbr_chr
 * EXAMPLE
 * 	ft_strlen("Hello world") --> 11
 */
size_t	ft_strlen(const char *s)
{
	size_t	nbr_chr;

	nbr_chr = 0;
	while (s[nbr_chr])
		nbr_chr++;
	return (nbr_chr);
}

/* FUNC STRCHR
 * 	detect char in a str
 * VAR
 * 	str: (char) is a copy of str and we manipulate this var
 * CODE
 * 	1. str = s
 * 	2. if str != c iterate
 * 	3. if str == c return str iterated
 * RETURN
 * 	str
 * EXAMPLE
 * 	ft_strchr("Hello world", 'w') --> "world"
 */
char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}

/* FUNC STRJOIN
 * 	join two str
 * VAR
 * 	s3:  (char) new str that we operate
 * 	tmp: (char) save of s3
 * RETURN
 * 	tmp
 * EXAMPLE
 * 	ft_strjoin("hello"," world") --> "hello world"
 */
char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	s3 = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	tmp = s3;
	while (*s1)
		*s3++ = *s1++;
	while (*s2)
		*s3++ = *s2++;
	*s3 = '\0';
	return (tmp);
}
