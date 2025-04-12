/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 20:49:31 by tcali             #+#    #+#             */
/*   Updated: 2025/04/10 20:49:31 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
fct which calculates the length of the initial part of str until a character
in sep is found.
Returns nb of chars before first occurence.
*/
size_t	ft_strcspn(const char *str, const char *sep)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (sep[j])
		{
			if (str[i] == sep[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
