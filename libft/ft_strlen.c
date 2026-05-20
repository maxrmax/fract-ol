/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxrmax <maxrmax>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:11:04 by maxrmax           #+#    #+#             */
/*   Updated: 2025/01/27 13:00:54 by maxrmax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

// Counts the length of the string excluding \0

// #include <stdio.h>
// int	main(void)
// {
// 	char str[] = "four";
// 	printf("%d\n", ft_strlen(str));
// }
