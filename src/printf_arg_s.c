/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_arg_s.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/29 01:38:02 by abobas        #+#    #+#                 */
/*   Updated: 2020/04/29 01:38:02 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>

static char		*ft_make_precision_str(t_check check)
{
	int		i;
	char	*dest;

	dest = (char*)malloc(sizeof(char) * (check.precision_value + 1));
	if (!dest)
	{
		free(check.arg_string);
		return (0);
	}
	i = 0;
	while (i < check.precision_value)
	{
		dest[i] = check.arg_string[i];
		i++;
	}
	dest[i] = '\0';
	free(check.arg_string);
	return (dest);
}

t_check			ft_make_s(va_list args, t_check check)
{
	char	*temp;

	temp = va_arg(args, char *);
	if (!temp)
	{
		check.arg_string = ft_strdup("(null)");
		if (!check.arg_string)
			return (check);
	}
	else
	{
		check.arg_string = ft_strdup(temp);
		if (!check.arg_string)
			return (check);
	}
	if (check.precision_true)
		check.arg_string = ft_make_precision_str(check);
	return (check);
}
