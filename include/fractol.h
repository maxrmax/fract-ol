/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:04:23 by mring             #+#    #+#             */
/*   Updated: 2025/04/01 15:05:21 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 860
# define HEIGHT 640

typedef struct s_fractol
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	char		**av;
	int			ac;
	int			set;
	int			max_iter;
	int			iter;
	float		zoom;
	double		min_x;
	double		min_y;
	double		max_x;
	double		max_y;
	double		julia_r;
	double		julia_i;
	double		offset_x;
	double		offset_y;
	uint32_t	color_shift;
}				t_fractol;

void			redraw(t_fractol *fractol);
void			init(t_fractol *fractol, int ac, char **av);
void			prompt(void);
void			scroll_func(double xdelta, double ydelta, void *param);
void			key_func(mlx_key_data_t mkd, void *param);
int				calculate_mandelbrot(double x, double y, t_fractol *fractol);
int				calculate_julia(double x, double y, t_fractol *fractol);
int				calculate_burning_ship(double x, double y, t_fractol *data);
float			ft_atof(const char *str);

#endif
