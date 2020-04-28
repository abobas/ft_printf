/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_utility_2.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/29 01:39:32 by abobas        #+#    #+#                 */
/*   Updated: 2020/04/29 01:39:32 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>
#include <stdlib.h>

static void		ft_putstr_null(char *s, t_check check)
{
	int		len;
	int		i;

	i = 0;
	if (check.flag_justify_true)
	{
		write(1, &(s[i]), 1);
		s[i] = 'a';
		i++;
	}
	len = (check.flag_justify_true) ? ft_strlen(s) : ft_strlen(s) + 1;
	while (i < len)
	{
		write(1, &(s[i]), 1);
		i++;
	}
}

void			ft_putstr(char *s, t_check check)
{
	int		i;

	i = 0;
	if (check.null_true)
		ft_putstr_null(s, check);
	else
	{
		while (s[i] != '\0')
		{
			write(1, &(s[i]), 1);
			i++;
		}
	}
}

static int		ft_digitcount(unsigned long a, int base)
{
	int	i;

	i = 0;
	while (a)
	{
		a = a / base;
		i++;
	}
	return (i);
}

static char		*ft_fillstring(char *dest, unsigned long n, int i, int base)
{
	unsigned long	b;

	dest[i] = '\0';
	i--;
	while (n >= (unsigned long)base)
	{
		b = n % base;
		if (b < 10)
			dest[i] = b + 48;
		else if (b >= 10)
			dest[i] = b + 'a' - 10;
		n = n / base;
		i--;
	}
	if (n < 10)
		dest[i] = n + 48;
	else
		dest[i] = (n + 'a' - 10);
	return (dest);
}

char			*ft_itoa_base(unsigned long n, int base)
{
	char	*dest;

	dest = (char*)malloc(sizeof(char) * (ft_digitcount(n, base) + 1));
	if (!dest)
		return (0);
	dest = ft_fillstring(dest, n, ft_digitcount(n, base), base);
	return (dest);
}
