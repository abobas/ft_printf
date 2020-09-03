/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_write_1.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/29 01:39:45 by abobas        #+#    #+#                 */
/*   Updated: 2020/04/29 01:39:45 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>

static t_check	ft_write_string(t_check check)
{
	if (check.temp_string)
	{
		check.temp_counter = ft_strlen(check.temp_string);
		if (check.null_true && !check.flag_justify_true)
			check.temp_counter++;
		check = ft_make_temp(check);
		ft_putstr(check.temp_string, check);
	}
	else
	{
		if (check.null_true)
			check.temp_counter = 1;
		else
			check.temp_counter = ft_strlen(check.arg_string);
		ft_putstr(check.arg_string, check);
	}
	return (check);
}

t_check			ft_write(va_list args, t_check check)
{
	check = ft_make_arg(args, check);
	if (!check.arg_string)
		return (check);
	if (check.field_width_value > ft_strlen(check.arg_string))
	{
		check = ft_make_field_width(check);
		if (!check.temp_string)
		{
			free(check.arg_string);
			return (check);
		}
	}
	check = ft_write_string(check);
	if (check.temp_string)
		free(check.temp_string);
	free(check.arg_string);
	return (check);
}

t_check			ft_make_arg(va_list args, t_check check)
{
	if (check.conversion_value == 's')
		check = ft_make_s(args, check);
	if (check.conversion_value == 'c')
		check = ft_make_c(args, check);
	if (check.conversion_value == 'd')
		check = ft_make_d(args, check);
	if (check.conversion_value == 'u')
		check = ft_make_u(args, check);
	if (check.conversion_value == 'x')
		check = ft_make_x(args, check);
	if (check.conversion_value == 'X')
		check = ft_make_x_2(args, check);
	if (check.conversion_value == 'p')
		check = ft_make_p(args, check);
	if (check.conversion_value == '%')
		check = ft_make_per(check);
	return (check);
}
