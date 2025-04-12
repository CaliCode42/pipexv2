/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 00:01:57 by tcali             #+#    #+#             */
/*   Updated: 2025/04/10 15:43:49 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "../includes/ft_printf.h"
#include "../includes/libft.h"

void	ft_check_prefix(t_printf *list)
{
	if (ft_present("cs", list->format.specifier)
		|| list->format.prefix_checked)
		return ;
	if (list->format.is_negative)
		ft_putformat(list, '-');
	else if (list->format.hash)
	{
		if (list->format.uppercase)
		{
			ft_putformat(list, '0');
			ft_putformat(list, 'X');
		}
		else if (list->format.lowercase)
		{
			ft_putformat(list, '0');
			ft_putformat(list, 'x');
		}
	}
	else if (list->format.space && !list->format.is_negative)
		ft_putformat(list, ' ');
	else if (list->format.plus && !list->format.is_negative)
		ft_putformat(list, '+');
	list->format.prefix_checked = 1;
}

static void	ft_handle_precision_str(t_printf *list, char *str)
{
	int	i;

	i = 0;
	if (list->format.precision == 0)
	{
		ft_putchar_fd(list->fd, '\0');
		return ;
	}
	else
	{
		while (i < list->format.precision)
		{
			ft_putformat(list, str[i]);
			i++;
		}
	}
}

void	ft_putstr(t_printf *list, char *str)
{
	int	precision;

	precision = list->format.precision;
	if (!str)
		return ;
	ft_check_prefix(list);
	if (list->format.specifier == 's'
		&& precision >= 0 && precision < ft_strlen_int(str))
	{
		ft_handle_precision_str(list, str);
	}
	else
	{
		while (*str)
		{
			ft_putformat(list, *str);
			str++;
		}
	}
}
