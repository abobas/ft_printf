/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_write_2.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/29 01:39:51 by abobas        #+#    #+#                 */
/*   Updated: 2020/04/29 01:39:51 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>

static t_check	ft_make_temp_util(t_check check, int pos, int i, int len)
{
	if (!check.flag_justify_true)
		while (pos < check.field_width_value)
		{
			if (check.int_negative_true && check.flag_padding_true \
				&& !check.precision_true)
			{
				check.temp_string[0] = '-';
				check.int_negative_true = 0;
				i++;
				pos++;
			}
			check.temp_string[pos] = check.arg_string[i];
			i++;
			pos++;
		}
	else
		while (i < len)
		{
			check.temp_string[i] = check.arg_string[i];
			i++;
		}
	return (check);
}

t_check			ft_make_temp(t_check check)
{
	int		pos;
	int		i;
	int		len;

	i = 0;
	pos = check.field_width_value - ft_strlen(check.arg_string);
	len = (check.null_true) ? 1 : ft_strlen(check.arg_string);
	check = ft_make_temp_util(check, pos, i, len);
	return (check);
}

t_check			ft_make_field_width(t_check check)
{
	int		i;
	int		len;

	i = 0;
	if (check.null_true && !check.flag_justify_true)
		check.field_width_value--;
	len = check.field_width_value + 1;
	check.temp_string = (char*)malloc(sizeof(char) * len);
	if (!check.temp_string)
		return (check);
	check.temp_string[check.field_width_value] = '\0';
	while (i < check.field_width_value)
	{
		if (check.flag_padding_true && !check.precision_true && \
			!check.flag_justify_true)
			check.temp_string[i] = '0';
		else
			check.temp_string[i] = ' ';
		i++;
	}
	return (check);
}
