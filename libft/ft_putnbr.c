/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:19:34 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/04/21 21:24:05 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb, int base)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb > 9)
		count += ft_putnbr((nb / base), base);
	if (nb < 0)
	{
		nb *= -1;
		count += ft_putchar('-', 1);
		count += ft_putnbr(nb, base);
	}
	else
		count += ft_putchar(nb % base + '0', 1);
	return (count);
}
