/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:01:15 by r-afonso          #+#    #+#             */
/*   Updated: 2023/06/18 17:18:15 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct s_list_printf
{
	char			*type;
	char			*content;
	t_list_printf	*next;
}					t_list_printf;

void				lstclear(t_list_printf **lst);
void	lstadd_back(t_list_printf **lst,
					t_list_printf *new_l);
t_list_printf		*lstnew(void *content);

#endif