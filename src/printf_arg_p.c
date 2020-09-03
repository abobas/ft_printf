/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_arg_p.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/29 01:37:46 by abobas        #+#    #+#                 */
/*   Updated: 2020/04/29 01:37:46 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>

static t_check		ft_make_precision_output(t_check check, char *temp)
{
	int		i;
	int		pos;
	int		len;

	i = 0;
	len = check.precision_value + 1;
	check.arg_string = (char*)malloc(sizeof(char) * len);
	if (!check.arg_string)
		return (check);
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
	free(temp);
	return (check);
}

static t_check		ft_make_precision(va_list args, t_check check)
{
	unsigned long	arg;
	char			*temp;

	arg = va_arg(args, unsigned long);
	if (arg == 0 && check.precision_value == 0)
	{
		check.arg_string = ft_strdup("");
		return (check);
	}
	temp = ft_itoa_base(arg, 16);
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

t_check				ft_make_p(va_list args, t_check check)
{
	unsigned long	arg;

	if (check.precision_true)
		check = ft_make_precision(args, check);
	else
	{
		arg = va_arg(args, unsigned long);
		if (arg == 0)
			check.arg_string = ft_strdup("0");
		else
			check.arg_string = ft_itoa_base(arg, 16);
	}
	check.arg_string = ft_ident(check.arg_string);
	return (check);
}
