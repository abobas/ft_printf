/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_read_3.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/29 01:39:10 by abobas        #+#    #+#                 */
/*   Updated: 2020/04/29 01:39:10 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>
#include <stdarg.h>

static t_check		ft_read_precision_util_2(const char *format, \
					t_check check, int len)
{
	char	*str;
	int		y;

	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (check);
	y = 0;
	while (format[check.index] >= '0' && format[check.index] <= '9')
	{
		str[y] = format[check.index];
		y++;
		check.index++;
	}
	str[y] = '\0';
	check.precision_value = ft_atoi(str);
	free(str);
	return (check);
}

static t_check		ft_read_precision_util_1(const char *format, t_check check)
{
	int		len;
	int		y;

	len = 0;
	y = check.index;
	while (format[y] >= '0' && format[y] <= '9')
	{
		y++;
		len++;
	}
	check = ft_read_precision_util_2(format, check, len);
	check.index--;
	return (check);
}

t_check				ft_read_precision(const char *format, va_list args, \
					t_check check)
{
	check.index++;
	check.precision_true = 1;
	if (format[check.index] == '*')
	{
		check.precision_value = va_arg(args, int);
		if (check.precision_value < 0)
		{
			check.precision_value = 0;
			check.precision_true = 0;
		}
	}
	else
		check = ft_read_precision_util_1(format, check);
	return (check);
}
