/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:32:30 by mring             #+#    #+#             */
/*   Updated: 2025/03/31 19:33:27 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

float	ft_atof(const char *str)
{
	float	res;
	float	sign;
	int		i;
	float	f;

	res = 0.0f;
	sign = 1;
	i = 0;
	while (str[i] == 9 || str[i] == 10 || str[i] == 11 || str[i] == 12
		|| str[i] == 13 || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = 1 - 2 * (str[i++] == '-');
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + str[i++] - '0';
	if (str[i] == '.')
		i++;
	f = 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i++] - '0';
		f *= 10;
	}
	return (sign * res / f);
}

void	prompt(void)
{
	ft_printf("  !!! INVALID PARAMETERS PROVIDED !!!  \n\n");
	ft_printf("OPTIONS:\n");
	ft_printf("---------------------------------------\n");
	ft_printf("| \"-m\":                               |\n");
	ft_printf("| Displays the Mandelbrot set fractal |\n");
	ft_printf("|                                     |\n");
	ft_printf("| \"-j\":                               |\n");
	ft_printf("| Displays the Julia set fractal      |\n");
	ft_printf("|                                     |\n");
	ft_printf("| e.g. \"-j 0 0.35\"                    |\n");
	ft_printf("---------------------------------------\n\n");
	exit(1);
}
