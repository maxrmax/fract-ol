/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:27:54 by mring             #+#    #+#             */
/*   Updated: 2025/04/01 14:49:15 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
