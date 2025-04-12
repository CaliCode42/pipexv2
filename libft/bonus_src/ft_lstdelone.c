/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:46:35 by tcali             #+#    #+#             */
/*   Updated: 2025/03/25 23:36:58 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
lst: The node to free.
del: The address of the function used to delete the content.

Takes as a parameter a node and frees the memory of the node’s 
content using the function ’del’ given as a parameter and free
the node. The memory of ’next’ must not be freed.
*/
#include <stdlib.h>
#include "../includes/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(t_content))
{
	if (!del)
		return ;
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}
