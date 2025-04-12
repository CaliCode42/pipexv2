/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:25:10 by tcali             #+#    #+#             */
/*   Updated: 2025/03/25 23:56:19 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_atoi_base(t_printf *list)
{
	const char	*numbers;
	int			numerator;

	numbers = "0123456789";
	numerator = 0;
	while (ft_present(numbers, *list->str))
		numerator = (numerator * 10) + (*list->str++ - '0');
	return (numerator);
}
