/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_threejoin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:46:59 by tcali             #+#    #+#             */
/*   Updated: 2025/04/22 13:47:48 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_str_threejoin(char const *s1, char const *s2, char const *s3)
{
	char	*str;
	size_t	len1;
	size_t	len2;
	size_t	len3;
	size_t	total_len;

	if (!s1 || !s2 || !s3)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len3 = ft_strlen(s3);
	total_len = len1 + len2 + len3 + 1;
	str = (char *)malloc(sizeof(char) * total_len);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, total_len);
	ft_strlcat(str, s2, total_len);
	ft_strlcat(str, s3, total_len);
	return (str);
}
