/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 11:33:29 by mstegema      #+#    #+#                 */
/*   Updated: 2022/10/31 15:51:15 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <string.h>

static void	ft_print_ph(const char *placeholder, int i, va_list ap)
{
	char	c;
	char	*str;
	// void	*ptr;

	if (placeholder[i] == 'c')
	{
		c = va_arg(ap, int);
		write (1, &c, 1);
	}
	else if (placeholder[i] == 's')
	{
		str = va_arg(ap, char *);
		write(1, str, strlen(str));
	}
	// else if (placeholder[i] == 'p')
	// {
	// 	ptr = va_arg(ap, void *);
	// 	write(1, str, strlen(str));
	// }
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
	char	*ptr = NULL;

	c = '5';
	ft_printf("ft: this should print %%\n");
	printf("og: this should print %%\n");
	ft_printf("ft: this is string 1: %s & this is string 2: %s\n", "abc", "123");
	printf("og: this is string 1: %s & this is string 2: %s\n", "abc", "123");
	ft_printf("ft :this is char 1: %c & this is char 2: %c\n", 'c', c);
	printf("og :this is char 1: %c & this is char 2: %c\n", 'c', c);
	// ft_printf(" ft: this is void ptr 1: %p & this is void ptr 2: %c\n", 'c', c);
	printf("og: this is void ptr 1: %p & this is void ptr 2: %p\n", ptr, &c);
	return (0);
}
