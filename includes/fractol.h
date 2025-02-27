/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalons <vicalons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:08:27 by vicalons          #+#    #+#             */
/*   Updated: 2025/02/26 17:15:26 by vicalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"
# include "math.h"
# include <stdlib.h>

# define MANDELBROT 1
# define MANDELBROT_STR "mandelbrot"
# define JULIA 2
# define JULIA_STR "julia"
# define JULIA_6 3
# define JULIA_6_STR "julia_6"
# define MAGIC 0
# define MAGIC_STR "magic"

# define WIN_SIZE 1024
# define BLACK 0x000000
# define WHITE 0xFFFFFF

// KEYS NUMPAD X11 
# define KEY_ESC 0xff1b
# define KEY_LEFT 0xff51
# define KEY_UP 0xff52
# define KEY_RIGHT 0xff53
# define KEY_DOWN 0xff54

# define KEY_PLUS 0xffab
# define KEY_MINUS 0xffad

# define KEY_1 0x031
# define KEY_2 0x032
# define KEY_3 0x033
# define KEY_0 0x030

# define KEY_SPC 0x0020

# define M_SCRL_UP 4
# define M_SCRL_DOWN 5

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_fractal
{
	double		zoom;
	double		set_x;
	double		set_y;
	int			type;
	int			iter;
	t_complex	z_init;
}	t_fractal;

typedef struct s_image
{
	void	*img;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
}	t_image;

typedef struct s_graph
{
	void		*mlx;
	void		*win;
	t_fractal	fractal;
	t_image		image;
	int			key_hook;
	int			expose_hook;
	int			exit_hook;
}	t_graph;

// Start ft
void		ft_options(void);
void		ft_graph(t_graph *graph);
void		ft_initfractal(t_graph *graph);
void		ft_error(char *msg);
double		ft_atof(char *str);
// Draw fractal
void		ft_draw(t_graph *graph);
double		ft_scale(double nbr, double min, double max, double old_max);
t_complex	ft_fractal(t_complex *z, t_complex *c, t_graph *graph);
// key and mouse hook
int			ft_keyhook(int key, t_graph *graph);
int			ft_close(t_graph *graph);
int			ft_mousehook(int key, int x, int y, t_graph *graph);
#endif
