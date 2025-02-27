/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalons <vicalons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:19:59 by vicalons          #+#    #+#             */
/*   Updated: 2025/02/20 13:21:42 by vicalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(t_graph *graph)
{
	mlx_destroy_image(graph->mlx, graph->image.img);
	mlx_destroy_window(graph->mlx, graph->win);
	mlx_destroy_display(graph->mlx);
	free(graph->mlx);
	exit(EXIT_SUCCESS);
}
