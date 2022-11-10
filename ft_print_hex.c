/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_hex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 14:50:18 by mstegema      #+#    #+#                 */
/*   Updated: 2022/11/10 13:36:12 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
// #include <stdio.h>

// This is the function that converts decimal numbers to hex.

// I went off from the ft_putnbr function and recreated it to prints hexidecimal
// numbers. It first checks if the number is 15 or smaller. If so it prints the
// the corresponding char. If not, it recursively calls on the function with
// "num / 16" and "num % 16" so it's remainder get's printed every call.

// It also checks which placeholder it is. If it's %X it'll print the hex in
// uppercase. Else (%x and %p) it'll print it in lowercase.

int	ft_print_hex(unsigned long num, char x, int res)
{
	char	c;

	if (num < 16)
	{
		if (num < 10)
			c = '0' + num;
		else if (x == 'X')
			c = '7' + num;
		else
			c = 'W' + num;
		res = ft_putchar(c) + res;
	}
	else
	{
		ft_print_hex(num / 16, x, res);
		ft_print_hex(num % 16, x, res);
	}
	return (res);
}

// This is what i used to check if the conversion went right.

// int	main(void)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 65546)
// 	{
// 		ft_print_hex(i, 'x');
// 		printf(" <- hex\n");
// 		printf("%i <- int\n\n", i);
// 		i = i + 321;
// 	}
// 	return (0);
// }
