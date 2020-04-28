/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_arg_d.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/29 01:36:08 by abobas        #+#    #+#                 */
/*   Updated: 2020/04/29 01:36:08 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>

static t_check		ft_precision_util(t_check check, char *temp, int len, \
					int pos)
{
	int		i;

	i = 0;
	if (check.int_negative_true)
	{
		pos++;
		check.arg_string[i] = '-';
		i++;
	}
	while (i < pos)
	{
		check.arg_string[i] = '0';
		i++;
	}
	i = (check.int_negative_true) ? 1 : 0;
	while (pos < len)
	{
		check.arg_string[pos] = temp[i];
		i++;
		pos++;
	}
	check.arg_string[pos] = '\0';
	return (check);
}

static t_check		ft_make_precision_output(t_check check, char *temp)
{
	int		extra;
	int		pos;
	int		len;

	extra = (check.int_negative_true) ? 2 : 1;
	len = check.precision_value + extra;
	check.arg_string = (char*)malloc(sizeof(char) * len);
	if (!check.arg_string)
		return (check);
	pos = len - ft_strlen(temp) - 1;
	check = ft_precision_util(check, temp, len, pos);
	return (check);
}

static t_check		ft_make_precision(va_list args, t_check check)
{
	int		arg;
	char	*temp;

	arg = va_arg(args, int);
	if (arg < 0)
		check.int_negative_true = 1;
	if (arg == 0 && check.precision_value == 0)
	{
		check.arg_string = ft_strdup("");
		return (check);
	}
	temp = ft_itoa(arg);
	if (!temp)
		return (check);
	if (ft_strlen(temp) > check.precision_value)
	{
		check.arg_string = temp;
		return (check);
	}
	check = ft_make_precision_output(check, temp);
	free(temp);
	return (check);
}

t_check				ft_make_d(va_list args, t_check check)
{
	if (check.precision_true)
		check = ft_make_precision(args, check);
	else
	{
		check.arg_string = ft_itoa(va_arg(args, int));
		if (check.arg_string[0] == '-')
			check.int_negative_true = 1;
	}
	return (check);
}
