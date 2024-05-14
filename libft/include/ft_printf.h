/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 23:20:04 by marvin            #+#    #+#             */
/*   Updated: 2023/12/22 23:20:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(int c);
int	ft_putstr(char *str);

int	ft_putnbr_rcs(long int n, int len);
int	ft_putnbr(int nb);
int	ft_putunbr_rcs(unsigned int n, int len);
int	ft_putunbr(int nb);

int	ft_putptr_rcs(size_t num, int len);
int	ft_putptr(size_t num);
int	ft_puthex_rcs(unsigned int num, const char format, int len);
int	ft_puthex(unsigned int num, const char format);

int	ft_validac(va_list *args, char type);
int	ft_printf(const char *str, ...);

#endif
