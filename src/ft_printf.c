/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: r-afonso < r-afonso@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 00:45:08 by r-afonso          #+#    #+#             */
/*   Updated: 2023/06/30 14:57:05 by r-afonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	print_cs(char **str, va_list args)
{
	int		number_c;
	char	param_c;
	char	*param_str;

	number_c = -1;
	if (**str == 'c')
	{
		param_c = va_arg(args, int);
		write(1, &param_c, 1);
		(*str)++;
		number_c += 2;
	}
	else
	{
		param_str = va_arg(args, char *);
		while (++number_c, *param_str)
		{
			write(1, param_str, 1);
			param_str++;
		}
		(*str)++;
	}
	return (number_c);
}

static int	print_diu(char **str, long int param_n)
{
	char	*param_str;
	int		number_c;

	number_c = -1;	
	param_str = ft_itoa(param_n);
	while (++number_c, *param_str)
	{
		write(1, param_str, 1);
		param_str++;
	}
	(*str)++;
	return (number_c);
}

static int	print_xp(char **str, va_list args)
{
	return (0);
}

static int	print_control(char **str, va_list args)
{
	int	number_n;

	(*str)++;
	// OK
	if (**str == 'c' || **str == 's')
		number_n = print_cs(str, args);
	else if (**str == 'x' || **str == 'X' || **str == 'p')
		number_n = print_xp(str, args);
	else if (**str == 'd' || **str == 'i' || **str == 'u')
		number_n = print_diu(str, va_arg(args, unsigned long));
	else
	{
		if (**str == '%')
			write(1, "%", 1);
		number_n = 1;
	}
	return (number_n);
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
