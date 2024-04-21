/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:18:26 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/04/21 21:21:57 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, int fd)
{
	int	count;

	count = 0;
	if (!s)
		return (ft_putstr("(null)", 1));
	while (*s)
	{
		write(fd, s, 1);
		s++;
		count++;
	}
	return (count);
}
