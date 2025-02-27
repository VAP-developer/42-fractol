/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalons <vicalons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:51:36 by vicalons          #+#    #+#             */
/*   Updated: 2025/02/26 17:36:17 by vicalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_options(void)
{
	ft_printf("\n");
	ft_printf("+----------------------------------------------------------+\n");
	ft_printf("|  Basic format:   ./fractol [name fractal] [z_init]       |\n");
	ft_printf("|                                                          |\n");
	ft_printf("| ======================================================== |\n");
	ft_printf("|                                                          |\n");
	ft_printf("|  KEY 1 --> mandelbrot [NO z_init]                        |\n");
	ft_printf("|  KEY 2 --> julia      [z_init.re] [z_init.im]            |\n");
	ft_printf("|  KEY_3 --> julia_6    [z_init.re] [z_init.im]            |\n");
	ft_printf("|  KEY_0 --> magic      [z_init.re] [z_init.im]            |\n");
	ft_printf("+----------------------------------------------------------+\n");
	ft_printf("\n");
	exit(EXIT_SUCCESS);
}
