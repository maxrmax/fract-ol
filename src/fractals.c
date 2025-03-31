/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:29:59 by mring             #+#    #+#             */
/*   Updated: 2025/03/31 18:19:38 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calculate_mandelbrot(double x, double y, t_fractol *fractol)
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

int	calculate_julia(double x, double y, t_fractol *fractol)
{
	int		i;
	double	zx;
	double	zy;
	double	zx_temp;

	i = 0;
	zx = x;
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
