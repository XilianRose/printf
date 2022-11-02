/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_hex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/02 14:50:18 by mstegema      #+#    #+#                 */
/*   Updated: 2022/11/02 15:25:29 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <string.h>

int	ft_print_hex(int num)
{
	char	c;

	c = '0';
	if (num < 16)
	{
		if (num < 10)
			c = '0' + num;
		else if (num < 16)
			c = '7' + num;
		ft_putchar(c);
	}
	return (0);
}

int	main(void)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		printf("int: %i\nhex: ", i);
		ft_print_hex(i);
		printf("\n");
		i++;
	}
	return (0);
}
