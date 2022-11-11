/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mstegema <mstegema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 11:34:06 by mstegema      #+#    #+#                 */
/*   Updated: 2022/11/11 11:46:08 by mstegema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *c, ...);

int		ft_print_str(char *s);
int		ft_print_char(char c);
int		ft_print_nbr(int n);
int		ft_print_uns(unsigned int n, int res);
int		ft_print_hex(unsigned long num, char x, int res);

size_t	ft_strlen(const char *s);
int		ft_intlen(int n);

#endif
