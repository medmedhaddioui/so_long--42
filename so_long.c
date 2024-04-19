/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:14:15 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/04/19 11:14:08 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	o;
	t_var imgs;

	if (ac != 2)
		ft_error("Map file not exist\n");
	o.len = ft_strlen(av[1]) - 4;
	if (strncmp(&av[1][o.len],".ber",4))
		ft_error("wrong file\n");
	o.fd = open(av[1], O_RDONLY, 0666);
	if (o.fd == -1)
		exit(1);
	read_from_file(&o);
	parsing(&o);
	create_window(&imgs, &o);
	return (0);
}
