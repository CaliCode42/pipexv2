/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcali <tcali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:35:29 by tcali             #+#    #+#             */
/*   Updated: 2025/03/25 23:37:17 by tcali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
lst: The address of a pointer to a node.
f: The address of the function used to iterate on the list.
del: The address of the function used to delete the content of a node if needed.

Iterates the list ’lst’ and applies the function ’f’ on the content of each 
node. Creates a new list resulting of the successive applications of the 
function ’f’. The ’del’ function is used to delete the content of a node 
if needed.
*/

#include <stdlib.h>
#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_content (*f)(t_content),
			void (*del)(t_content))
{
	t_list	*head;
	t_list	*node;
	t_list	*tail;

	if (!f || !del || !lst)
		return (NULL);
	head = NULL;
	tail = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (node == NULL)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		if (tail)
			tail->next = node;
		else
			head = node;
		tail = node;
		lst = lst->next;
	}
	return (head);
}
