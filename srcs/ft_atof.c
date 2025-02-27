/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalons <vicalons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:06:18 by vicalons          #+#    #+#             */
/*   Updated: 2025/02/26 14:51:50 by vicalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_sgn(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

static int	is_float(char *str)
{
	int	i;
	int	point;

	i = 0;
	point = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
		{
			if (str[i] == '.')
				point += 1;
			if (point > 1)
				return (1);
			i++;
		}
		else
			return (1);
	}
	return (0);
}

double	ft_atof(char *str)
{
	long	integer;
	double	decimal;
	double	power;
	int		sgn;

	integer = 0;
	decimal = 0;
	sgn = 1;
	power = 1;
	if (is_float(str) == 1)
		ft_options();
	if (*str == '-' || *str == '+')
		sgn = ft_sgn(*str++);
	while (*str && *str != '.')
		integer = integer * 10 + (*str++ - '0');
	if (*str == '.')
		str++;
	while (*str)
	{
		power /= 10;
		decimal += (*str++ - '0') * power;
	}
	return ((integer + decimal) * sgn);
}
