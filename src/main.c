/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:27:54 by mring             #+#    #+#             */
/*   Updated: 2025/03/31 21:41:45 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	get_color(int iter, t_fractol *fractol)
{
	return (((iter * 5 + fractol->color_shift) % 256) << 16 | ((iter * 5
				+ fractol->color_shift) % 256) << 8 | ((iter * 5
				+ fractol->color_shift) % 256));
}

void	redraw(t_fractol *fractol)
{
	int	x;
	int	y;
	int	iter;

	x = 0;
	double mapped_x, mapped_y;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			mapped_x = (fractol->min_x + (x * (fractol->max_x - fractol->min_x))
					/ WIDTH) / fractol->zoom + fractol->offset_x;
			mapped_y = (fractol->min_y + (y * (fractol->max_y - fractol->min_y))
					/ HEIGHT) / fractol->zoom + fractol->offset_y;
			if (fractol->set == 1)
				iter = calculate_mandelbrot(mapped_x, mapped_y, fractol);
			else
				iter = calculate_julia(mapped_x, mapped_y, fractol);
			mlx_put_pixel(fractol->img, x, y, get_color(iter, fractol));
			y++;
		}
		x++;
	}
}

void	param(char **av, t_fractol *fractol)
{
	if (!ft_strncmp(av[1], "-m", 2))
		fractol->set = 1;
	else if (!ft_strncmp(av[1], "-j", 2))
	{
		fractol->set = 2;
		if (fractol->ac == 2)
		{
			fractol->julia_r = -0.835;
			fractol->julia_i = -0.2321;
		}
		else
		{
			fractol->julia_r = ft_atof(av[2]);
			fractol->julia_i = ft_atof(av[3]);
		}
	}
	else
		prompt();
}

void	init(t_fractol *fractol, int ac, char **av)
{
	fractol->mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", false);
	fractol->img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	fractol->ac = ac;
	fractol->av = av;
	fractol->max_iter = 100;
	fractol->zoom = 1.0;
	fractol->color_shift = 0;
	fractol->offset_x = 0;
	fractol->offset_y = 0;
	fractol->min_x = -2.0;
	fractol->max_x = 1.0;
	fractol->min_y = -1.5;
	fractol->max_y = 1.5;
	param(av, fractol);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (ac < 2)
		prompt();
	init(&fractol, ac, av);
	mlx_key_hook(fractol.mlx, key_func, &fractol);
	mlx_scroll_hook(fractol.mlx, scroll_func, &fractol);
	mlx_image_to_window(fractol.mlx, fractol.img, 0, 0);
	redraw(&fractol);
	mlx_loop(fractol.mlx);
	mlx_terminate(fractol.mlx);
	return (0);
}

// inline is a good optimization strategy for mathematical functions that are called many times.
// inline hints the compiler to copy the entire code into the call position.
// the compiler may decides to ignore this hint.
// can improve performance by eliminating function call overhead.
/*
- Global variables are forbidden
- Julia & Mandelbrot
- mouse wheel to zoom
- Julia parameters
- parameter for fractal set
- invalid parameter prompt
- colors for fractal depth visualization

bonus:
- a third fractal
- zoom follows mouse position
- arrow keys for movement
- color range shift

*/