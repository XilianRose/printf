/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 11:34:06 by mstegema      #+#    #+#                 */
/*   Updated: 2022/11/03 12:33:56 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *c, ...);
void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_print_xlo(int num);
void	ft_print_xup(int num);

#endif
