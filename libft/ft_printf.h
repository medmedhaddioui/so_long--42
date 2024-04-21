/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:18:31 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/04/21 21:26:11 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(int c, int fd);
int	ft_putstr(char *s, int fd);
int	ft_print_hex(long nb, int base, char c);
int	ft_hex_adress(unsigned long nb, unsigned int base, char c);
int	ft_putnbr(int nb, int base);
int	ft_print_u(unsigned int nb, int base);

#endif
