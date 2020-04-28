/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/29 01:39:58 by abobas        #+#    #+#                 */
/*   Updated: 2020/04/29 01:39:58 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static t_check	ft_proces(const char *format, va_list args, t_check check)
{
	check.index++;
	check = ft_read(format, check, args);
	check = ft_write(args, check);
	return (check);
}

int				ft_printf(const char *format, ...)
{
	va_list			args;
	t_check			check;
	int				counter;

	counter = 0;
	check = ft_set_check();
	va_start(args, format);
	while (format[check.index] != '\0')
	{
		if (format[check.index] != '%')
		{
			ft_putchar(format[check.index]);
			counter++;
		}
		if (format[check.index] == '%')
		{
			check = ft_proces(format, args, check);
			counter = counter + check.temp_counter;
			check = ft_reset_check(check);
		}
		check.index++;
	}
	va_end(args);
	return (counter);
}
