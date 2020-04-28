/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_arg_per.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/29 01:37:54 by abobas        #+#    #+#                 */
/*   Updated: 2020/04/29 01:37:54 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>

t_check				ft_make_per(t_check check)
{
	check.arg_string = (char*)malloc(sizeof(char) * 2);
	if (!check.arg_string)
		return (check);
	check.arg_string[0] = '%';
	check.arg_string[1] = '\0';
	return (check);
}
