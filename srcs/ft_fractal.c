/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalons <vicalons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:00:21 by vicalons          #+#    #+#             */
/*   Updated: 2025/02/26 14:35:31 by vicalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_abs(double nbr)
{
	if (nbr < 0)
		nbr = -nbr;
	return (nbr);
}

t_complex	ft_fractal(t_complex *z, t_complex *c, t_graph *graph)
{
	t_complex	result;

	if (graph->fractal.type == MANDELBROT)
	{
		result.re = z->re * z->re - z->im * z->im + c->re;
		result.im = 2 * z->re * z->im + c->im;
	}
	else if (graph->fractal.type == JULIA)
	{
		result.re = z->re * z->re - z->im * z->im + c->re;
		result.im = 2 * z->re * z->im + c->im;
	}
	else if (graph->fractal.type == JULIA_6)
	{
		result.re = pow(z->re, 6) - 15 * pow(z->re, 4) * pow(z->im, 2) \
			+ 15 * pow(z->re, 2) * pow(z->im, 4) + pow(z->im, 6) + c->re;
		result.im = 6 * pow(z->re, 5) * z->im - 20 * pow(z->re, 3) \
			* pow(z->im, 3) + 6 * pow(z->im, 5) * z->re + c->im;
	}
	else if (graph->fractal.type == MAGIC)
	{
		result.re = cosh(z->re) * cos(z->im) + c->re;
		result.im = sinh(z->re) * sin(z->im) + c->im;
	}
	return (result);
}
