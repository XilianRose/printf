/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 11:33:29 by mstegema      #+#    #+#                 */
/*   Updated: 2022/11/10 12:07:08 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

// This function prints the placeholders (ph).
//
// Using va_arg, arguments are initialized and pointers to the arguments of
// different types are added to the va_list. They are then printed using general
// ft_put~ functions or with the ft_print_hex function in case of %x, %X or %p.

static void	ft_print_ph(const char *ph, int i, va_list ap)
{
	char			c;
	char			*str;
	int				n;
	unsigned long	hex;

	if (ph[i] == 'c')
		return (c = va_arg(ap, int), ft_putchar(c));
	else if (ph[i] == 's')
		return (str = va_arg(ap, char *), ft_putstr(str));
	else if (ph[i] == 'd' || ph[i] == 'i')
		return (n = va_arg(ap, int), ft_putnbr(n));
	else if (ph[i] == 'x' || ph[i] == 'X' || ph[i] == 'p')
	{
		hex = va_arg(ap, unsigned long);
		if (ph[i] == 'p')
			ft_putstr("0x");
		return (ft_print_hex(hex, ph[i]));
	}
	return ;
}

// This is the function that prints every printable character.
//
// It iterates through the string and prints every character untill it finds
// an '%', then it checks if it should be printed or if it's a placeholder.
// If it's an placeholder it goes into ft_print_ph function.

static void	ft_print_cs(const char *c, va_list ap)
{
	int	i;

	i = 0;
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

// This is the general printf function. It takes a character string and an
// undefined number of arguments using variable argument list functions.
//
// The function then calls on ft_print_cs with the string and va_list.

int	ft_printf(const char *c, ...)
{
	va_list	ap;

	va_start(ap, c);
	ft_print_cs(c, ap);
	va_end(ap);
	return (0);
}

// Here i compare the output of the original function (og) to my function (ft)

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
	ft_printf("ft: this is hex 1: %x & this is HEX 2: %X\n", 635635, 635635);
	printf("og: this is hex 1: %x & this is HEX 2: %X\n\n", 635635, 635635);
	ft_printf("ft: this is void ptr 1: %p & this is void ptr 2: %p\n", ptr, &c);
	printf("og: this is void ptr 1: %p & this is void ptr 2: %p\n\n", ptr, &c);
	printf("og: this is decimal: %d & this is integer: %i\n", 012, 012);
	ft_printf("ft: this is decimal: %d & this is integer: %i\n\n", 012, 012);
	return (0);
}
