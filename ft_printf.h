/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 11:34:06 by mstegema      #+#    #+#                 */
/*   Updated: 2022/11/10 13:34:57 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *c, ...);

int		ft_print_hex(unsigned long num, char x, int res);

size_t	ft_strlen(const char *s);
int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_putuns(unsigned int n);
int		ft_putnbr(int n);

#endif