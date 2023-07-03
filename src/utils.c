/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:47:31 by r-afonso          #+#    #+#             */
/*   Updated: 2023/07/02 21:32:51 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	convert_to_hexa(char *result, unsigned long number)
{
	int				number_c;
	unsigned long	remainder;
	char			hex_number;

	number_c = 0;
	while (number != 0)
	{
		remainder = number % 16;
		if (remainder < 10)
			hex_number = remainder;
		else
			hex_number = 'a' + remainder - 10;
		*(result + number_c) = hex_number;
		number_c++;
		number /= 16;
	}
}