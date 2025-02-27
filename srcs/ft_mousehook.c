/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mousehook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalons <vicalons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:47:04 by vicalons          #+#    #+#             */
/*   Updated: 2025/02/26 14:23:31 by vicalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mousehook(int key, int x, int y, t_graph *graph)
{
	double		zoom_factor;
	double		position_x;
	double		position_y;

	if (key == M_SCRL_DOWN)
		zoom_factor = 1.05;
	else if (key == M_SCRL_UP)
		zoom_factor = 1 / 1.05;
	else
		zoom_factor = 1.0;
	if (zoom_factor != 1.0)
	{
		position_x = graph->fractal.set_x + ft_scale(x, -2, 2, WIN_SIZE) \
				* graph->fractal.zoom;
		position_y = graph->fractal.set_y + ft_scale(y, 2, -2, WIN_SIZE) \
				* graph->fractal.zoom;
		graph->fractal.zoom *= zoom_factor;
		graph->fractal.set_x = position_x - ft_scale(x, -2, 2, WIN_SIZE) \
				* graph->fractal.zoom;
		graph->fractal.set_y = position_y - ft_scale(y, 2, -2, WIN_SIZE) \
				* graph->fractal.zoom;
	}
	ft_draw(graph);
	return (0);
}
