/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyhook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalons <vicalons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:40:58 by vicalons          #+#    #+#             */
/*   Updated: 2025/02/26 17:18:19 by vicalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_changefractal(int key, t_graph *graph)
{
	if (key == KEY_1)
		graph->fractal.type = MANDELBROT;
	else if (key == KEY_2)
	{
		graph->fractal.type = JULIA;
		graph->fractal.z_init.re = -0.835;
		graph->fractal.z_init.im = -0.2321;
	}
	else if (key == KEY_3)
	{
		graph->fractal.type = JULIA_6;
		graph->fractal.z_init.re = 0.59;
		graph->fractal.z_init.im = 0;
	}
	else if (key == KEY_0)
	{
		graph->fractal.type = MAGIC;
		graph->fractal.z_init.re = -0.25;
		graph->fractal.z_init.im = -0.2;
	}
	ft_initfractal(graph);
}

static void	ft_changeview(int key, t_graph *graph)
{
	if (key == KEY_DOWN)
		graph->fractal.set_y += 0.1;
	else if (key == KEY_UP)
		graph->fractal.set_y -= 0.1;
	else if (key == KEY_LEFT)
		graph->fractal.set_x += 0.1;
	else if (key == KEY_RIGHT)
		graph->fractal.set_x -= 0.1;
}

static void	ft_changeiter(int key, t_graph *graph)
{
	if (key == KEY_PLUS && graph->fractal.iter < 256)
		graph->fractal.iter += 1;
	else if (key == KEY_MINUS && graph->fractal.iter > 0)
		graph->fractal.iter -= 1;
}

int	ft_keyhook(int key, t_graph *graph)
{
	if (key == KEY_ESC)
		ft_close(graph);
	else if (key == KEY_SPC)
		ft_initfractal(graph);
	else if (key >= KEY_LEFT && key <= KEY_DOWN)
		ft_changeview(key, graph);
	else if (key >= KEY_PLUS && key <= KEY_MINUS)
		ft_changeiter(key, graph);
	else if (key >= KEY_0 && key <= KEY_3)
		ft_changefractal(key, graph);
	ft_draw(graph);
	return (0);
}
