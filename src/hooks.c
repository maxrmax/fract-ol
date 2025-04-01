/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:31:05 by mring             #+#    #+#             */
/*   Updated: 2025/04/01 15:24:48 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom_at_position(t_fractol *fractol, double zoom_factor)
{
	double	mouse_x;
	double	mouse_y;
	int32_t	x;
	int32_t	y;

	x = 0;
	y = 0;
	mlx_get_mouse_pos(fractol->mlx, &x, &y);
	mouse_x = fractol->min_x + ((double)x / WIDTH) * (fractol->max_x
			- fractol->min_x);
	mouse_y = fractol->min_y + ((double)y / HEIGHT) * (fractol->max_y
			- fractol->min_y);
	fractol->min_x = mouse_x + (fractol->min_x - mouse_x) * zoom_factor;
	fractol->max_x = mouse_x + (fractol->max_x - mouse_x) * zoom_factor;
	fractol->min_y = mouse_y + (fractol->min_y - mouse_y) * zoom_factor;
	fractol->max_y = mouse_y + (fractol->max_y - mouse_y) * zoom_factor;
}

void	scroll_func(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractol;
	double		zoom_factor;

	(void)xdelta;
	fractol = (t_fractol *)param;
	if (ydelta > 0)
		zoom_factor = 1.1;
	else
		zoom_factor = 0.9;
	zoom_at_position(fractol, zoom_factor);
	redraw(fractol);
}

void	key_func(mlx_key_data_t mkd, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (mkd.key == MLX_KEY_ESCAPE)
	{
		mlx_terminate(fractol->mlx);
		exit(0);
	}
	if (mkd.key == MLX_KEY_UP && mkd.action == MLX_PRESS)
		fractol->offset_y -= (fractol->max_x - fractol->min_x) / 20.0;
	if (mkd.key == MLX_KEY_DOWN && mkd.action == MLX_PRESS)
		fractol->offset_y += (fractol->max_x - fractol->min_x) / 20.0;
	if (mkd.key == MLX_KEY_LEFT && mkd.action == MLX_PRESS)
		fractol->offset_x -= (fractol->max_x - fractol->min_x) / 20.0;
	if (mkd.key == MLX_KEY_RIGHT && mkd.action == MLX_PRESS)
		fractol->offset_x += (fractol->max_x - fractol->min_x) / 20.0;
	if (mkd.key == MLX_KEY_SPACE && mkd.action == MLX_PRESS)
		fractol->color_shift += 3;
	redraw(fractol);
}
