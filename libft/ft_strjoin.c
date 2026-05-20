/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxrmax <maxrmax>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:13:34 by maxrmax           #+#    #+#             */
/*   Updated: 2025/01/27 13:01:07 by maxrmax          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dst = malloc(s1_len + s2_len + 1);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, s1_len + 1);
	ft_strlcat(dst, s2, s1_len + s2_len + 2);
	return (dst);
}

// int	main(void)
// {
// 	char *str1 = "";
// 	char *str2 = "";
// 	printf("ft: %s\n", ft_strjoin(str1, str2));
// }
