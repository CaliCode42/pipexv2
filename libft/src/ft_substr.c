/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:02:21 by tcali             #+#    #+#             */
/*   Updated: 2025/03/25 23:39:43 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../includes/libft.h"

char	*ft_empty_str(void)
{
	char	*str;

	str = malloc(1);
	if (!str)
		return (NULL);
	if (str)
		str[0] = '\0';
	return (str);
}

char	*ft_subdup(char *dst, char const *s, size_t size, unsigned int start)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		dst[i] = s[start + i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	sub_len;
	char	*dst;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_empty_str());
	sub_len = s_len - start;
	if (sub_len > len)
		sub_len = len;
	dst = malloc (sizeof(char) * (sub_len + 1));
	if (!dst)
		return (NULL);
	return (ft_subdup(dst, s, sub_len, start));
}
