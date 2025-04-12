/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:35:21 by tcali             #+#    #+#             */
/*   Updated: 2025/03/25 23:56:51 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_parse_flags(t_printf *list)
{
	char	*flags;
	char	flag;

	flags = "-0+ #";
	flag = 0;
	while (ft_present(flags, *list->str))
	{
		flag = *list->str;
		if (flag == '-')
			list->format.left_justif = 1;
		else if (flag == '0')
			list->format.zero_pad = 1;
		else if (flag == '+')
			list->format.plus = 1;
		else if (flag == ' ')
			list->format.space = 1;
		else if (flag == '#')
			list->format.hash = 1;
		++list->str;
	}
}

static void	ft_get_numerator(t_printf *list, int *numerator)
{
	if (*list->str == '*')
	{
		*numerator = va_arg(list->ap, int);
		++list->str;
		return ;
	}
	*numerator = ft_atoi_base(list);
}

static void	ft_check_base(t_printf *list, char speci)
{
	if (ft_present("diu", speci))
		list->format.base = "0123456789";
	else if (ft_present("pxX", speci))
	{
		if (speci == 'p' || speci == 'x')
		{
			if (speci == 'p')
				list->format.hash = 1;
			list->format.base = "0123456789abcdef";
			list->format.lowercase = 1;
		}
		else if (speci == 'X')
		{
			list->format.base = "0123456789ABCDEF";
			list->format.uppercase = 1;
		}
	}
}

int	ft_parse_format(t_printf *list)
{
	char	*specifiers;

	specifiers = "cspdiuxX%";
	ft_memset(&list->format, 0, sizeof(t_format));
	list->format.precision = -1;
	ft_parse_flags(list);
	ft_get_numerator(list, &list->format.width);
	if (*list->str == '.' && *(++list->str))
	{
		ft_get_numerator(list, &list->format.precision);
	}
	if (!ft_present(specifiers, *list->str))
		return (-1);
	else
	{
		list->format.specifier = *list->str;
		ft_check_base(list, *list->str);
	}
	return (1);
}
