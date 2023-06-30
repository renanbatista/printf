/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:47:31 by r-afonso          #+#    #+#             */
/*   Updated: 2023/06/30 18:45:47 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*convert_to_hexa(unsigned long number)
{
	int				number_c;
	unsigned long	remainder;
	char			hex_number;
	char			result[20];
	
	number_c = 0;
	while (number != 0)
	{
		remainder = number % 16;
		if (remainder < 10)
			hex_number = remainder;
		else
			hex_number = 'a' + remainder - 10;
		result[number_c] = remainder;
		number_c++;
		number /= 16;
	}
	return (result);
}

int main()
{
	// printf("%x", 1234);
	convert_to_hexa(1234);
	return (0);
}
