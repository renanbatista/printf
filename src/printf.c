/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 00:45:08 by r-afonso          #+#    #+#             */
/*   Updated: 2023/06/22 20:48:35 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// conversões a lidar cspdiuxX%
#include "include/printf.h"

int	print_csp(char caracter, char *str)
{
	if (caracter == "c")
	{
		write(1, str, 1);
		return 1
	}
	
}

int	print_diu(char caracter, char *str)
{
}

int	print_x_percent(char caracter, char *str)
{
}

int	print_control(char **string, char *param)
{
	if (**string == '%')
	{
		if (*(*(string)) + 1 == 'c' || *(*(string)) + 1 == 's' || *(*(string))
			+ 1 == 'p')
			print_csp((char)*(*(string)) + 1, param);
		if (*(*(string)) + 1 == 'd' || *(*(string)) + 1 == 'i' || *(*(string))
			+ 1 == 'u')
			print_diu((char)*(*(string)) + 1, param);
		if (*(*(string)) + 1 == 'x' || *(*(string)) + 1 == 'X' || *(*(string))
			+ 1 == '%')
			print_x_percent((char)*(*(string)) + 1, param);
		(*(string)) += 2;
		return (2);
	}
	else
	{
		write(1, *string, 1);
		(*(string))++;
		return (1);
	}
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		type;
	char	*param;
	int		number_printed;

	number_printed = 0;
	va_start(args, string);
	while (*string)
	{
		if (*string != '%')
		{
			write(1, string, 1);
			string++;	
		}
		else 
		{
			param = va_arg(args, char *);
			number_printed += print_control((char **)&string, param);
			string+=2;
		}
	}
	return (1);
}

int	main(void)
{
	ft_printf("%d", 20);
	return (0);
}
