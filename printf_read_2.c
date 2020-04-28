/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_read_2.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/29 01:39:02 by abobas        #+#    #+#                 */
/*   Updated: 2020/04/29 01:39:02 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>

t_check				ft_read_field_width_1(va_list args, t_check check)
{
	int		arg;

	check.field_width_true = 1;
	arg = va_arg(args, int);
	if (arg < 0)
	{
		check.flag_justify_true = 1;
		arg = arg * -1;
	}
	check.field_width_value = arg;
	return (check);
}

static t_check		ft_read_field_width_util(const char *format, \
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
	check.field_width_value = ft_atoi(str);
	free(str);
	return (check);
}

t_check				ft_read_field_width_2(const char *format, t_check check)
{
	int		len;
	int		y;

	len = 0;
	y = check.index;
	check.field_width_true = 1;
	while (format[y] >= '0' && format[y] <= '9')
	{
		y++;
		len++;
	}
	check = ft_read_field_width_util(format, check, len);
	check.index--;
	return (check);
}
