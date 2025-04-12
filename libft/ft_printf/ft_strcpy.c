/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 22:47:07 by tcali             #+#    #+#             */
/*   Updated: 2025/03/25 23:57:16 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_strcpy(t_printf *list, char *src)
{
	char	*dst;

	if (!list || !src)
		return (0);
	list->format.itoa = malloc (sizeof(char) * (ft_strlen_int(src) + 1));
	if (!list->format.itoa)
		return (0);
	dst = list->format.itoa;
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (1);
}
