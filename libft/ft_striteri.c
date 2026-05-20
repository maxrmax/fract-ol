/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxrmax <maxrmax>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:23:32 by maxrmax           #+#    #+#             */
/*   Updated: 2025/01/27 13:01:11 by maxrmax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// char	functionname(unsigned int x, char c)
// {
// 	(void) x;
// 	(void) c;
// 	return ('g');
// }

// int	main(void)
// {
// 	char *s = ft_strieteri("some string", functionname);
// 	printf("s: %s\n", s);
// }

// // for every char in a string call f, return value of that into a new string
