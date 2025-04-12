/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_withzero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:31:39 by tcali             #+#    #+#             */
/*   Updated: 2025/03/25 23:56:37 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	ft_fill_withzero(char *str, size_t n)
{
	char	*ptr;

	ptr = str;
	while (n--)
		*ptr++ = '0';
	*ptr++ = '\0';
}
