/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 11:33:29 by mstegema      #+#    #+#                 */
/*   Updated: 2022/11/10 13:44:45 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// This function prints the placeholders (ph).
//
// Using va_arg, arguments are initialized and pointers to the arguments of
// different types are added to the va_list. They are then printed using general
// ft_put~ functions or with the ft_print_hex function in case of %x, %X or %p.

// It prints the "0x" part of the pointer address in this function because the
// functions used to print hexidecimals is recursive.

static int	ft_print_ph(const char *ph, int i, va_list ap, int res)
{
	char			c;
	char			*str;
	int				nbr;
	unsigned long	x;
	unsigned int	u;

	if (ph[i] == 'c')
		return (c = va_arg(ap, int), (ft_putchar(c) + res));
	else if (ph[i] == 's')
		return (str = va_arg(ap, char *), (ft_putstr(str) + res));
	else if (ph[i] == 'd' || ph[i] == 'i')
		return (nbr = va_arg(ap, int), (ft_putnbr(nbr) + res));
	else if (ph[i] == 'u')
		return (u = va_arg(ap, unsigned int), (ft_putnbr(u) + res));
	else if (ph[i] == 'x' || ph[i] == 'X' || ph[i] == 'p')
	{
		if (ph[i] == 'p')
			res = ft_putstr("0x") + res;
		return (x = va_arg(ap, unsigned long), ft_print_hex(x, ph[i], res));
	}
	return (res);
}

// This is the function that prints every printable character.
//
// It iterates through the string and prints every character untill it finds
// an '%', then it checks if it should be printed or if it's a placeholder.
// If it's an placeholder it goes into ft_print_ph function.

static int	ft_print_cs(const char *c, va_list ap, int res)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (c[i] != '%')
		{
			write(1, c + i, 1);
			i++;
			res++;
		}
		else if (c[i] == '%' && c[i + 1] == '%')
		{
			write(1, "%", 1);
			i = i + 2;
			res++;
		}
		else if (c[i] == '%' && c[i + 1] != '%')
		{
			res = ft_print_ph(c, i + 1, ap, res);
			i = i + 2;
		}
	}
	return (res);
}

// This is the general printf function. It takes a character string and an
// undefined number of arguments using variable argument list functions.
//
// int res is declared here and given to ft_print_cs with the string and
// va_list. It'll count the printed characters.

int	ft_printf(const char *c, ...)
{
	va_list	ap;
	int		res;

	res = 0;
	va_start(ap, c);
	res = ft_print_cs(c, ap, res);
	va_end(ap);
	return (res);
}

// Here i compare the output of the original function (og) to my function (ft)

int	main(void)
{
	char	c;
	void	*ptr;
	int		res_ft;
	int		res_og;

	c = '5';
	ptr = NULL;
	res_ft = ft_printf("ft: this should print %%\n");
	res_og = printf("og: this should print %%\n\n");
	res_ft = ft_printf("ft: this is a string: %s\n", "abc");
	res_og = printf("og: this is a string: %s\n\n", "abc");
	res_ft = ft_printf("ft: this is char 1: %c & this is char 2: %c\n", 'c', c);
	res_og = printf("og: this is char 1: %c & this is char 2: %c\n\n", 'c', c);
	res_ft = ft_printf("ft: this is hex: %x\n", 635635);
	res_og = printf("og: this is hex: %x\n\n", 635635);
	res_ft = ft_printf("ft: this is HEX: %X\n", 635635);
	res_og = printf("og: this is HEX: %X\n\n", 635635);
	res_ft = ft_printf("ft: this is void ptr: %p\n", &c);
	res_og = printf("og: this is void ptr: %p\n\n", &c);
	res_ft = ft_printf("ft: this is decimal: %d & this is integer: %i\n\n", 012, 012);
	res_og = printf("og: this is decimal: %d & this is integer: %i\n", 012, 012);
	res_ft = ft_printf("ft: this is unsigned decimal: %u\n\n", -12);
	res_og = printf("og: this is unsigned decimal: %u\n", -12);
	return (0);
}
