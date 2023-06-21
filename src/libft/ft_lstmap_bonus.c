/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 20:41:16 by r-afonso          #+#    #+#             */
/*   Updated: 2023/06/15 03:20:05 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*ini_node;

	if (lst == NULL || del == NULL || f == NULL)
		return (NULL);
	new_node = ft_lstnew(f(lst->content));
	if (new_node == NULL)
		return (NULL);
	ini_node = new_node;
	lst = lst->next;
	while (lst != NULL)
	{
		new_node->next = ft_lstnew(f(lst->content));
		if (!new_node->next)
		{
			ft_lstclear(&ini_node, del);
			return (NULL);
		}
		new_node = new_node->next;
		lst = lst->next;
	}
	return (ini_node);
}
