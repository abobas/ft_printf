/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_struct.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/29 01:39:17 by abobas        #+#    #+#                 */
/*   Updated: 2020/04/29 01:39:17 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_check		ft_set_check(void)
{
	t_check		check;

	check.index = 0;
	check.temp_counter = 0;
	check.flag_justify_true = 0;
	check.flag_padding_true = 0;
	check.precision_true = 0;
	check.precision_value = 0;
	check.field_width_true = 0;
	check.field_width_value = 0;
	check.conversion_value = '0';
	check.temp_string = 0;
	check.arg_string = 0;
	check.int_negative_true = 0;
	check.null_true = 0;
	return (check);
}

t_check		ft_reset_check(t_check check)
{
	check.temp_counter = 0;
	check.flag_justify_true = 0;
	check.flag_padding_true = 0;
	check.precision_true = 0;
	check.precision_value = 0;
	check.field_width_true = 0;
	check.field_width_value = 0;
	check.conversion_value = '0';
	check.temp_string = 0;
	check.arg_string = 0;
	check.int_negative_true = 0;
	check.null_true = 0;
	return (check);
}
