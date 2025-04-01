/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:47:58 by mring             #+#    #+#             */
/*   Updated: 2025/04/01 14:04:45 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static uint32_t	get_color(t_fractol *fractol)
{
	double	angle;
	int		r;
	int		g;
	int		b;
	float	gradient;

	gradient = 0.15;
	angle = gradient * fractol->iter + 0.1 * fractol->color_shift;
	r = (int)(255 * 0.5 * (1 + sin(angle)));
	g = (int)(255 * 0.5 * (1 + sin(angle + 2.094)));
	b = (int)(255 * 0.5 * (1 + sin(angle + 4.188)));
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

static void	set_check(double mapped_x, double mapped_y, t_fractol *fractol)
{
	if (fractol->set == 1)
		fractol->iter = calculate_mandelbrot(mapped_x, mapped_y, fractol);
	else if (fractol->set == 2)
		fractol->iter = calculate_julia(mapped_x, mapped_y, fractol);
	else
		fractol->iter = calculate_burning_ship(mapped_x, mapped_y, fractol);
}

void	redraw(t_fractol *fractol)
{
	int		x;
	int		y;
	double	mapped_x;
	double	mapped_y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			mapped_x = (fractol->min_x + (x * (fractol->max_x - fractol->min_x))
					/ WIDTH) / fractol->zoom + fractol->offset_x;
			mapped_y = (fractol->min_y + (y * (fractol->max_y - fractol->min_y))
					/ HEIGHT) / fractol->zoom + fractol->offset_y;
			set_check(mapped_x, mapped_y, fractol);
			mlx_put_pixel(fractol->img, x, y, get_color(fractol));
			y++;
		}
		x++;
	}
}

static void	param(char **av, t_fractol *fractol)
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
		else if (fractol->ac == 4)
		{
			printf("test");
			fractol->julia_r = ft_atof(av[2]);
			fractol->julia_i = ft_atof(av[3]);
		}
		else
			prompt();
	}
	else if (!ft_strncmp(av[1], "-bs", 3))
		fractol->set = 3;
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
