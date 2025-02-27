/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initfractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalons <vicalons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:09:33 by vicalons          #+#    #+#             */
/*   Updated: 2025/02/20 16:06:52 by vicalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_initfractal(t_graph *graph)
{
	graph->fractal.iter = 15;
	graph->fractal.zoom = 1;
	graph->fractal.set_x = 0;
	graph->fractal.set_y = 0;
}
