/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_adress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:18:02 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/04/21 21:25:46 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_adress(unsigned long nb, unsigned int base, char c)
{
	char	*base_hex;
	int		count;

	count = 0;
	base_hex = "0123456789abcdef";
	if (c == 'p')
	{
		ft_putstr("0x", 1);
		count = 2;
	}
	c = 'x';
	if (nb < base)
		count += ft_putchar(base_hex[nb], 1);
	else
	{
		count += ft_hex_adress(nb / base, base, c);
		count += ft_putchar((base_hex[nb % base]), 1);
	}
	return (count);
}
