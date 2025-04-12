/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:57:35 by tcali             #+#    #+#             */
/*   Updated: 2025/03/25 23:57:26 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_put_n_char(t_printf *list, int precision, char c)
{
	if (precision <= 0)
		return ;
	while (precision--)
		ft_putformat(list, c);
}

void	ft_printchar(t_printf *list, int c, char pad)
{
	int		width;

	width = list->format.width;
	if (width > 1)
	{
		if (list->format.left_justif)
		{
			ft_put_n_char(list, 1, (char)c);
			ft_put_n_char(list, (width - 1), pad);
		}
		else
		{
			if (list->format.zero_pad)
				pad = '0';
			ft_put_n_char(list, (width - 1), pad);
			ft_put_n_char(list, 1, (char)c);
		}
	}
	else
		ft_put_n_char(list, 1, (char)c);
}

static void	ft_check_zeropad(t_printf *list)
{
	int	str_len;

	if (list->format.specifier == 's')
		str_len = ft_strlen_int(list->format.str);
	else if (ft_present("pdiuxX", list->format.specifier))
		str_len = ft_strlen_int(list->format.itoa);
	if (list->format.zero_pad)
	{
		ft_check_prefix(list);
		ft_put_n_char(list, ((list->format.width) - str_len), '0');
		ft_pickstr(list);
	}
	else
	{
		ft_put_n_char(list, ((list->format.width) - str_len), ' ');
		ft_pickstr(list);
	}
}

void	ft_printstr(t_printf *list, char *str)
{
	if (!str)
		str = "(null)";
	if (list->format.precision >= 0 && list->format.specifier != 's')
		ft_check_precision(list, str);
	else
	{
		if (list->format.specifier == 's')
			list->format.str = str;
	}
	if (list->format.width < 1)
	{
		ft_pickstr(list);
		return ;
	}
	if (list->format.left_justif)
	{
		ft_pickstr(list);
		ft_put_n_char(list, ((list->format.width) - ft_strlen_int(str)), ' ');
	}
	else
		ft_check_zeropad(list);
}

void	ft_print_nb(t_printf *list, char speci)
{
	ft_convert_nb(list, speci);
	if (list->format.itoa)
	{
		ft_check_width(list);
		ft_printstr(list, list->format.itoa);
	}
	if (list->format.itoa)
		free(list->format.itoa);
}
