/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 11:33:29 by mstegema      #+#    #+#                 */
/*   Updated: 2022/11/09 15:17:48 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <string.h>

static void	ft_print_ph(const char *placeholder, int i, va_list ap)
{
	char			c;
	char			*str;
	unsigned long	x;
	int				n;

	if (placeholder[i] == 'c')
	{
		c = va_arg(ap, int);
		return (ft_putchar(c));
	}
	else if (placeholder[i] == 's')
	{
		str = va_arg(ap, char *);
		return (ft_putstr(str));
	}
	else if (placeholder[i] == 'x' || placeholder[i] == 'X'
		|| placeholder[i] == 'p')
	{
		x = va_arg(ap, unsigned long);
		if (placeholder[i] == 'p')
			ft_putstr("0x");
		return (ft_print_hex(x, placeholder[i]));
	}
	else if (placeholder[i] == 'd' || placeholder[i] == 'i')
	{
		n = va_arg(ap, int);
		return (ft_putnbr(n));
	}
	return ;
}

static void	ft_print_cs(const char *c, int i, va_list ap)
{
	while (c[i])
	{
		if (c[i] != '%')
		{
			write(1, c + i, 1);
			i++;
		}
		else if (c[i] == '%' && c[i + 1] == '%')
		{
			write(1, "%", 1);
			i = i + 2;
		}
		else if (c[i] == '%' && c[i + 1] != '%')
		{
			ft_print_ph(c, i + 1, ap);
			i = i + 2;
		}
	}
	return ;
}

int	ft_printf(const char *c, ...)
{
	va_list	ap;

	va_start(ap, c);
	ft_print_cs(c, 0, ap);
	va_end(ap);
	return (0);
}

int	main(void)
{
	char	c;
	void	*ptr = NULL;

	c = '5';
	ft_printf("ft: this should print %%\n");
	printf("og: this should print %%\n\n");
	ft_printf("ft: this is string 1: %s & this is string 2: %s\n", "abc", "123");
	printf("og: this is string 1: %s & this is string 2: %s\n\n", "abc", "123");
	ft_printf("ft: this is char 1: %c & this is char 2: %c\n", 'c', c);
	printf("og: this is char 1: %c & this is char 2: %c\n\n", 'c', c);
	ft_printf("ft: this is hex 1: %x & this is hex 2: %X\n", 635635, 635635);
	printf("og: this is hex 1: %x & this is hex 2: %X\n\n", 635635, 635635);
	ft_printf("ft: this is void ptr 1: %p & this is void ptr 2: %p\n", ptr, &c);
	printf("og: this is void ptr 1: %p & this is void ptr 2: %p\n\n", ptr, &c);
	printf("og: this is decimal: %d & this is integer: %i\n", 012, 012);
	ft_printf("ft: this is decimal: %d & this is integer: %i\n\n", 012, 012);
	return (0);
}
