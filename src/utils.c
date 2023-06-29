/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:47:31 by r-afonso          #+#    #+#             */
/*   Updated: 2023/06/28 20:20:48 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr_updated(int n)
{
	long int	n_l;

	
}
n_l = n;
if (n_l < 0)
{
	ft_putchar_fd('-', 1);
	n_l = n_l * -1;
}
if (n_l >= 10)
	ft_putnbr_fd(n_l / 10, 1);
putnbr_updated((n_l % 10) + '0');