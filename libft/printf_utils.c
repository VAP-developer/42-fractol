/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalons <vicalons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:49:54 by vicalons          #+#    #+#             */
/*   Updated: 2025/01/22 11:57:13 by vicalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_printchar(const int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

size_t	ft_printstr(const char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (ft_printstr("(null)"));
	while (str[count])
		count += ft_printchar(str[count]);
	return (count);
}

size_t	ft_printnbr(int nbr, const char *base, int len_base)
{
	size_t	count;

	count = 0;
	if (nbr < 0)
	{
		if (nbr == -2147483648 && len_base == 10)
			return (ft_printstr("-2147483648"));
		else if (nbr == -2147483648 && len_base == 16)
			return (ft_printstr("80000000"));
		count += ft_printchar('-');
		nbr = -nbr;
	}
	if (nbr / len_base > 0)
	{
		count += ft_printnbr(nbr / len_base, base, len_base);
		count += ft_printnbr(nbr % len_base, base, len_base);
	}
	else
		count += ft_printchar(base[nbr]);
	return (count);
}

size_t	ft_printunsgn(unsigned long long nbr, const char *base, int len_base)
{
	int	count;

	count = 0;
	if (nbr / len_base > 0)
	{
		count += ft_printunsgn(nbr / len_base, base, len_base);
		count += ft_printunsgn(nbr % len_base, base, len_base);
	}
	else
		count += ft_printchar(base[nbr]);
	return (count);
}

size_t	ft_printptr(void *ptr)
{
	int					count;
	unsigned long long	ptr_ad;

	if (ptr == NULL)
		return (ft_printstr("(nil)"));
	count = 0;
	ptr_ad = (unsigned long long)ptr;
	count = ft_printstr("0x") + ft_printunsgn(ptr_ad, HEX_LOW, 16);
	return (count);
}
