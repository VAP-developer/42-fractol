/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalons <vicalons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 08:24:28 by vicalons          #+#    #+#             */
/*   Updated: 2025/02/26 14:18:48 by vicalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_setfractal(t_graph *graph, char **param)
{
	if (!graph || !param)
	{
		ft_printf("Error 1\n");
		return ;
	}
	if (ft_strcmp(param[1], MANDELBROT_STR) != 0)
	{
		graph->fractal.z_init.re = ft_atof(param[2]);
		graph->fractal.z_init.im = ft_atof(param[3]);
	}
	if (ft_strcmp(param[1], JULIA_STR) == 0)
		graph->fractal.type = JULIA;
	else if (ft_strcmp(param[1], MANDELBROT_STR) == 0)
		graph->fractal.type = MANDELBROT;
	else if (ft_strcmp(param[1], JULIA_6_STR) == 0)
		graph->fractal.type = JULIA_6;
	else if (ft_strcmp(param[1], MAGIC_STR) == 0)
		graph->fractal.type = MAGIC;
	else
		ft_options();
}

int	main(int argc, char **argv)
{
	t_graph	graph;

	if (argc >= 2 || argc <= 4)
	{
		if (argc == 2 && (!ft_strcmp(argv[1], "mandelbrot")))
			ft_setfractal(&graph, argv);
		else if (argc == 4 && (!ft_strcmp(argv[1], "julia") || \
					!ft_strcmp(argv[1], "magic") || \
					!ft_strcmp(argv[1], "julia_6")))
			ft_setfractal(&graph, argv);
		else
			ft_options();
	}
	else
		ft_options();
	ft_graph(&graph);
	ft_draw(&graph);
	mlx_key_hook(graph.win, ft_keyhook, &graph);
	mlx_mouse_hook(graph.win, ft_mousehook, &graph);
	mlx_hook(graph.win, 17, 0, ft_close, &graph);
	mlx_loop(graph.mlx);
	return (0);
}
