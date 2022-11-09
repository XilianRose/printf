/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_x.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 14:50:18 by mstegema      #+#    #+#                 */
/*   Updated: 2022/11/09 15:04:52 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
// #include <stdio.h>
// #include <string.h>

void	ft_print_hex(unsigned long num, char x)
{
	char	c;
	int		rem;

	if (num < 16)
	{
		if (num < 10)
			c = '0' + num;
		else
			c = '7' + num;
		ft_putchar(c);
	}
	else
	{
		ft_print_hex(num / 16, x);
		rem = num % 16;
		if (rem < 10)
			c = '0' + rem;
		else if (x == 'X')
			c = '7' + rem;
		else
			c = 'W' + rem;
		ft_putchar(c);
	}
}

// int	main(void)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 65546)
// 	{
// 		ft_print_xlo(i);
// 		printf(" <- hex\n");
// 		printf("%i <- int\n\n", i);
// 		i = i + 321;
// 	}
// 	return (0);
// }
