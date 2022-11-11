/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utils.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/31 13:42:00 by mstegema      #+#    #+#                 */
/*   Updated: 2022/11/11 10:47:36 by mstegema      ########   odam.nl         */
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
