/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utils.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 13:42:00 by mstegema      #+#    #+#                 */
/*   Updated: 2022/11/10 13:24:59 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

// int	ft_putuns(unsigned int n)
// {
// 	char	c;

// 	if (n < 10)
// 	{
// 		c = '0' + n;
// 		ft_putchar(c);
// 	}
// 	else
// 	{
// 		ft_putuns(n / 10);
// 		ft_putuns(n % 10);
// 	}
// }

int	ft_intlen(int n)
{
	size_t	i;

	i = 0;
	if ((n == 0) || (n < 0))
		i = 1;
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

int	ft_putnbr(int n)
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
		ft_putnbr(n % 10);
	}
	return (ft_intlen(n));
}
