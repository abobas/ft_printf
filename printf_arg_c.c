/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_arg_c.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/29 01:35:58 by abobas        #+#    #+#                 */
/*   Updated: 2020/04/29 01:35:58 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>

t_check				ft_make_c(va_list args, t_check check)
{
	unsigned char	arg;

	arg = (unsigned char)va_arg(args, int);
	if (arg == '\0')
		check.null_true = 1;
	check.arg_string = (char*)malloc(sizeof(char) * 2);
	if (!check.arg_string)
		return (check);
	check.arg_string[0] = arg;
	check.arg_string[1] = '\0';
	return (check);
}
