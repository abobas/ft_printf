/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_utility_1.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/29 01:39:24 by abobas        #+#    #+#                 */
/*   Updated: 2020/04/29 01:39:24 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>
#include <unistd.h>

void		ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

char		*ft_str_upper(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

static int	ft_longcheck(unsigned long a, int b)
{
	int	c;

	if (a > 2147483647 && a < 9223372036854775807)
	{
		c = -2147483648 - (2147483647 - a + 1);
		return (c);
	}
	if (a > 9223372036854775807)
	{
		c = (b == -1) ? 0 : -1;
		return (c);
	}
	c = (b == -1) ? a * -1 : a;
	return (c);
}

int			ft_atoi(const char *str)
{
	unsigned long	a;
	int				b;
	int				c;

	a = 0;
	b = 1;
	c = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		b = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		a = a * 10 + *str - '0';
		str++;
	}
	c = ft_longcheck(a, b);
	return (c);
}

char		*ft_ident(char *str)
{
	char	*dst;
	int		i;
	int		y;

	i = 0;
	y = 0;
	dst = (char*)malloc(sizeof(char) * (ft_strlen(str) + 3));
	if (!dst)
	{
		free(str);
		return (0);
	}
	dst[i] = '0';
	i++;
	dst[i] = 'x';
	i++;
	while (str[y] != '\0')
	{
		dst[i] = str[y];
		i++;
		y++;
	}
	dst[i] = '\0';
	free(str);
	return (dst);
}
