/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:51:18 by tcali             #+#    #+#             */
/*   Updated: 2025/03/25 23:57:11 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_render_format(t_printf *list)
{
	char	specifier;
	char	pad;

	specifier = list->format.specifier;
	pad = list->format.pad;
	pad = ' ';
	if (specifier == '%')
		ft_printchar(list, '%', pad);
	else if (specifier == 'c')
		ft_printchar(list, va_arg(list->ap, int), pad);
	else if (specifier == 's')
		ft_printstr(list, va_arg(list->ap, char *));
	if (ft_present("pdiuxX", specifier))
		ft_print_nb(list, specifier);
}
