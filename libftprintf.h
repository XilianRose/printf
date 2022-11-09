/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 11:34:06 by mstegema      #+#    #+#                 */
/*   Updated: 2022/11/09 15:04:57 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *c, ...);
void	ft_print_hex(unsigned long num, char x);

size_t	ft_strlen(const char *s);
void	ft_putstr(char *s);
void	ft_putchar(char c);
void	ft_putnbr(int n);

#endif
