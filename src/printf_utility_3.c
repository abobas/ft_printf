/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_utility_3.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: abobas <abobas@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/29 01:39:39 by abobas        #+#    #+#                 */
/*   Updated: 2020/04/29 01:39:39 by abobas        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdlib.h>

int				ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char			*ft_strdup(char *s1)
{
	char	*dst;
	int		i;

	i = ft_strlen(s1);
	dst = (char*)malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static int		ft_digitcount(int a)
{
	int	i;

	i = 0;
	while (a >= 10 || a <= -10)
	{
		a = a / 10;
		i++;
	}
	i++;
	if (a < 0)
		i++;
	return (i);
}

static char		*ft_fillstring(char *dest, int n, int i)
{
	long	x;
	int		b;

	x = n;
	if (x < 0)
	{
		dest[0] = '-';
		x = x * -1;
	}
	dest[i] = '\0';
	i--;
	while (x >= 10)
	{
		b = x % 10;
		x = x / 10;
		dest[i] = b + '0';
		i--;
	}
	dest[i] = (x % 10 + '0');
	return (dest);
}

char			*ft_itoa(int n)
{
	int		i;
	char	*dest;

	dest = (char*)malloc(sizeof(char) * (ft_digitcount(n) + 1));
	if (!dest)
		return (0);
	i = ft_digitcount(n);
	dest = ft_fillstring(dest, n, i);
	return (dest);
}
