/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxrmax <maxrmax>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:59:20 by maxrmax           #+#    #+#             */
/*   Updated: 2025/01/27 12:58:52 by maxrmax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;

	copy = (char *)malloc((ft_strlen(s1) * sizeof(char)) + 1);
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s1, ft_strlen(s1) + 1);
	return (copy);
}

// int	main(void)
// {
// 	char *str;
// 	str = "test";
// 	printf("nn:%s \n", strdup(str));
// 	printf("ft:%s \n", ft_strdup(str));
// }
