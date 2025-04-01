/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:29:59 by mring             #+#    #+#             */
/*   Updated: 2025/04/01 14:01:53 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

inline int	calculate_mandelbrot(double x, double y, t_fractol *fractol)
{
	int		i;
	double	zx;
	double	zy;
	double	zx_temp;

	i = 0;
	zx = 0;
	zy = 0;
	while (i < fractol->max_iter)
	{
		zx_temp = zx * zx - zy * zy + x;
		zy = 2.0 * zx * zy + y;
		zx = zx_temp;
		if (zx * zx + zy * zy > 4)
			return (i);
		i++;
	}
	return (i);
}

inline int	calculate_julia(double x, double y, t_fractol *fractol)
{
	int		i;
	double	zx;
	double	zy;
	double	zx_temp;

	i = 0;
	zx = -x;
	zy = y;
	while (i < fractol->max_iter)
	{
		zx_temp = zx * zx - zy * zy + fractol->julia_r;
		zy = 2.0 * zx * zy + fractol->julia_i;
		zx = zx_temp;
		if (zx * zx + zy * zy > 4)
			return (i);
		i++;
	}
	return (i);
}

int	calculate_burning_ship(double x, double y, t_fractol *data)
{
	int		i;
	double	cx;
	double	cy;
	double	x0;
	double	y0;

	i = 0;
	cx = x;
	cy = y;
	x = 0;
	y = 0;
	while (i < data->max_iter)
	{
		x0 = x * x - y * y + cx;
		y0 = 2.0 * fabs(x * y) + cy;
		x = fabs(x0);
		y = fabs(y0);
		if (x * x + y * y > 4)
		{
			return (i);
		}
		i++;
	}
	return (i);
}
