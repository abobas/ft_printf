/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_arg_x_1.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/29 01:38:30 by abobas        #+#    #+#                 */
/*   Updated: 2020/04/29 01:38:30 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>

static t_check		ft_make_precision_util(t_check check, char *temp, int len)
{
	int		pos;
	int		i;

	i = 0;
	pos = len - ft_strlen(temp) - 1;
	while (i < pos)
	{
		check.arg_string[i] = '0';
		i++;
	}
	i = 0;
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
	int		len;

	len = check.precision_value + 1;
	check.arg_string = (char*)malloc(sizeof(char) * len);
	if (!check.arg_string)
	{
		free(temp);
		return (check);
	}
	check = ft_make_precision_util(check, temp, len);
	free(temp);
	return (check);
}

static t_check		ft_make_precision(va_list args, t_check check)
{
	unsigned int	arg;
	char			*temp;

	arg = va_arg(args, unsigned int);
	if (arg == 0 && check.precision_value == 0)
	{
		check.arg_string = ft_strdup("");
		return (check);
	}
	temp = ft_itoa_base((unsigned long)arg, 16);
	if (!temp)
		return (check);
	if (ft_strlen(temp) > check.precision_value)
	{
		check.arg_string = temp;
		return (check);
	}
	check = ft_make_precision_output(check, temp);
	return (check);
}

t_check				ft_make_x(va_list args, t_check check)
{
	unsigned int	arg;

	if (check.precision_true)
		check = ft_make_precision(args, check);
	else
	{
		arg = va_arg(args, unsigned int);
		if (arg == 0)
		{
			check.arg_string = ft_strdup("0");
			return (check);
		}
		check.arg_string = ft_itoa_base((unsigned long)arg, 16);
	}
	return (check);
}
