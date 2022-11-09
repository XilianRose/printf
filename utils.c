/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 13:42:00 by mstegema      #+#    #+#                 */
/*   Updated: 2022/11/09 15:14:19 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else if (n < 10)
	{
		c = '0' + n;
		ft_putchar(c);
	}
	else
	{
		ft_putnbr(n / 10);
		c = '0' + (n % 10);
		ft_putchar(c);
	}
}
