/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>               +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by tcali             #+#    #+#             */
/*   Updated: 2025/04/10 18:40:00 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
Extracts a token from *str_ptr using chars in sep as separators.
Returns a pointer to token and updates str_ptr to point after separator,
or NULL if no token found.
*/
char	*ft_strsep(char **str_ptr, const char *sep)
{
	char	*start;
	char	*p;

	if (!str_ptr || !*str_ptr)
		return (NULL);
	start = *str_ptr;
	p = start + ft_strcspn(start, sep);
	if (*p)
	{
		*p = '\0';
		*str_ptr = p + 1;
	}
	else
		*str_ptr = NULL;
	return (start);
}
