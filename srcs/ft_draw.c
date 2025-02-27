/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalons <vicalons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:22:35 by vicalons          #+#    #+#             */
/*   Updated: 2025/02/26 14:22:08 by vicalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_pixel(int x, int y, t_graph *graph, int color)
{
	int		set;

	set = (y * graph->image.size_line) + (x * (graph->image.bpp / 8));
	*(unsigned int *)(graph->image.data + set) = color;
}

static int	ft_color(int i, int min_color, int max_color, int iter)
{
	return (((max_color - min_color) / iter) * i);
}

static void	ft_setjulia(t_complex *z, t_complex *c, t_graph *graph)
{
	if (graph->fractal.type == JULIA || graph->fractal.type == JULIA_6 \
			|| graph->fractal.type == MAGIC)
	{
		c->re = graph->fractal.z_init.re;
		c->im = graph->fractal.z_init.im;
	}
	else if (graph->fractal.type == MANDELBROT)
	{
		c->re = z->re;
		c->im = z->im;
	}
}

static void	ft_fractalpixel(int x, int y, t_complex z, t_graph *graph)
{
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	ft_setjulia(&z, &c, graph);
	while (i < graph->fractal.iter)
	{
		z = ft_fractal(&z, &c, graph);
		if ((z.re * z.re + z.im * z.im) > 4)
		{
			color = ft_color(i, BLACK, WHITE, graph->fractal.iter);
			ft_pixel(x, y, graph, color);
			return ;
		}
		i++;
	}
	ft_pixel(x, y, graph, BLACK);
}

void	ft_draw(t_graph *graph)
{
	t_complex	z;
	int			x;
	int			y;

	mlx_clear_window(graph->mlx, graph->win);
	y = -1;
	while (++y < WIN_SIZE)
	{
		x = -1;
		z.im = ft_scale(y, 2, -2, WIN_SIZE) * graph->fractal.zoom \
			+ graph->fractal.set_y;
		while (++x < WIN_SIZE)
		{
			z.re = ft_scale(x, -2, 2, WIN_SIZE) * \
				graph->fractal.zoom + graph->fractal.set_x;
			ft_fractalpixel(x, y, z, graph);
		}
	}
	mlx_put_image_to_window(graph->mlx, graph->win, graph->image.img, 0, 0);
}
