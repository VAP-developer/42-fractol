/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalons <vicalons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:49:39 by vicalons          #+#    #+#             */
/*   Updated: 2025/01/22 12:03:09 by vicalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printspecial(const char c, va_list vad)
{
	size_t	count;

	count = 0;
	if (c == 'c')
		count = ft_printchar(va_arg(vad, int));
	else if (c == '%')
		count = ft_printchar('%');
	else if (c == 's')
		count = ft_printstr(va_arg(vad, char *));
	else if (c == 'd' || c == 'i')
		count = ft_printnbr(va_arg(vad, int), DECIMAL, 10);
	else if (c == 'x')
		count = ft_printunsgn(va_arg(vad, unsigned int), HEX_LOW, 16);
	else if (c == 'X')
		count = ft_printunsgn(va_arg(vad, unsigned int), HEX_UPP, 16);
	else if (c == 'u')
		count = ft_printunsgn(va_arg(vad, unsigned int), DECIMAL, 10);
	else if (c == 'p')
		count = ft_printptr(va_arg(vad, void *));
	return (count);
}

int	ft_printf(char const *str, ...)
{
	va_list	vad;
	char	*sp;
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	va_start(vad, str);
	sp = "cspdiuxX%";
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '\0' && ft_strchr(sp, str[i + 1]))
		{
			count += ft_printspecial(str[i + 1], vad);
			i++;
		}
		else if (str[i] == '%' && str[i +1] == '\0')
			return (-1);
		else
			count += ft_printchar(str[i]);
		i++;
	}
	va_end(vad);
	return (count);
}
