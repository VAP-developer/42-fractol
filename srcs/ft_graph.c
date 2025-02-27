/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalons <vicalons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:00:22 by vicalons          #+#    #+#             */
/*   Updated: 2025/02/20 13:14:36 by vicalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_image(t_graph *graph)
{
	graph->image.img = mlx_new_image(graph->mlx, WIN_SIZE, WIN_SIZE);
	if (!graph->image.img)
	{
		mlx_destroy_window(graph->mlx, graph->win);
		mlx_destroy_display(graph->mlx);
		free(graph->mlx);
		ft_error("Error mlx_image.");
	}
}

static void	ft_window(t_graph *graph)
{
	graph->win = mlx_new_window(graph->mlx, WIN_SIZE, WIN_SIZE, "FRACTOL");
	if (!graph->win)
	{
		mlx_destroy_display(graph->mlx);
		free(graph->mlx);
		ft_error("Error mlx_window.");
	}
}

static void	ft_mlx(t_graph *graph)
{
	graph->mlx = mlx_init();
	if (!graph->mlx)
		ft_error("Error mlx_init.");
}

void	ft_graph(t_graph *graph)
{
	int	bpp;
	int	size_line;
	int	endian;

	if (!graph)
		return ;
	ft_initfractal(graph);
	ft_mlx(graph);
	ft_window(graph);
	ft_image(graph);
	graph->image.data = mlx_get_data_addr(graph->image.img, \
			&bpp, &size_line, &endian);
	graph->image.bpp = bpp;
	graph->image.size_line = size_line;
	graph->image.endian = endian;
}
