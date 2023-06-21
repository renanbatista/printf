/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:13:05 by r-afonso          #+#    #+#             */
/*   Updated: 2023/06/18 17:15:23 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/printf.h"

void	lstclear(t_list_printf **lst)
{
	t_list_printf	*new_node;
	t_list_printf	*next;

	if (lst == NULL)
		return ;
	new_node = *lst;
	while (new_node != NULL)
	{
		next = new_node->next;
		free(new_node->content);
		free(new_node->type);
		free(new_node);
		new_node = next;
	}
	*lst = NULL;
}

void	lstadd_back(t_list_printf **lst, t_list_printf *new_l)
{
	t_list_printf	*last;

	if (lst == NULL || new_l == NULL)
		return ;
	else if (*lst == NULL)
		*lst = new_l;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new_l;
	}
}

t_list_printf	*lstnew(void *content)
{
	t_list_printf *new_node;

	new_node = (t_list_printf *)malloc(sizeof(t_list_printf));
	if (new_node)
	{
		new_node->content = content;
		new_node->next = NULL;
	}
	return (new_node);
}