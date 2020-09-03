/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_read_1.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/29 01:38:51 by abobas        #+#    #+#                 */
/*   Updated: 2020/04/29 01:38:51 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int			ft_read_condition(const char *format, t_check check)
{
	if (format[check.index] == 's')
		return (0);
	if (format[check.index] == 'd')
		return (0);
	if (format[check.index] == 'i')
		return (0);
	if (format[check.index] == 'u')
		return (0);
	if (format[check.index] == 'c')
		return (0);
	if (format[check.index] == 'x')
		return (0);
	if (format[check.index] == 'X')
		return (0);
	if (format[check.index] == 'p')
		return (0);
	if (format[check.index] == '%')
		return (0);
	return (1);
}

static t_check		ft_read_conversion(const char *format, t_check check)
{
	if (format[check.index] == 's')
		check.conversion_value = 's';
	if (format[check.index] == 'd' || format[check.index] == 'i')
		check.conversion_value = 'd';
	if (format[check.index] == 'u')
		check.conversion_value = 'u';
	if (format[check.index] == 'c')
		check.conversion_value = 'c';
	if (format[check.index] == 'x')
		check.conversion_value = 'x';
	if (format[check.index] == 'X')
		check.conversion_value = 'X';
	if (format[check.index] == 'p')
		check.conversion_value = 'p';
	if (format[check.index] == '%')
		check.conversion_value = '%';
	return (check);
}

t_check				ft_read(const char *format, t_check check, va_list args)
{
	while (ft_read_condition(format, check))
	{
		if (format[check.index] == '0')
			check.flag_padding_true = 1;
		else if (format[check.index] == '-')
			check.flag_justify_true = 1;
		else if (format[check.index] == '*')
			check = ft_read_field_width_1(args, check);
		else if (format[check.index] >= '1' && format[check.index] <= '9')
			check = ft_read_field_width_2(format, check);
		else if (format[check.index] == '.')
			check = ft_read_precision(format, args, check);
		check.index++;
	}
	check = ft_read_conversion(format, check);
	return (check);
}
