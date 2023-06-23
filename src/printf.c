/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 00:45:08 by r-afonso          #+#    #+#             */
/*   Updated: 2023/06/23 17:02:05 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// conversões a lidar cspdiuxX%
#include "../include/printf.h"

int	print_cs(char **str, va_list args)
{
	int	number_c;

	number_c = 0;
	if (**str == 'c')
	{
		write(1, param, 1);
		(*str)++;
		number_c++;
	}
	else if (**str == 's')
	{
		while (*param)
		{
			write(1, param, 1);
			param++;
			number_c++;
		}
	}
	else
		return (0);
	return (number_c);
}

int	print_diu(char **str, int param)
{
	return (0);
}

int	print_x(char **str, char *param)
{
	return (0);
}

int	print_p(char **str, char *param)
{
	return (0);
}

int	print_control(char **str, va_list args)
{
	int	number_c;

	(*str)++;
	if (**str == 'c' || **str == 's' || **str == 'p' || **str == '%')
	{
		if (**str == '%')
			number_c = print_x(str + 1, va_arg(args, char *));
		else
		{
			number_c = print_cs(str + 1, args);
		}
	}
	else
		number_c = print_diu(str + 1, va_arg(args, int));
	return (number_c);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		number_printed;

	number_printed = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str != '%')
		{
			write(1, str, 1);
			str++;
		}
		else
			number_printed += print_control((char **)&str, args);
	}
	va_end(args);
	return (number_printed);
}

int	main(void)
{
	ft_printf("%c", 'a');
	return (0);
}
