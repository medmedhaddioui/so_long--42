/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:14:15 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/04/17 16:15:41 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_from_file(t_data *o)
{
	o->i = 0;
	o->nbstr = 0;
	o->m = get_next_line(o->fd);
	if (!o->m)
		ft_error("Map not valid\n");
	while (1)
	{
		o->line[o->i] = get_next_line(o->fd);
		if (!o->line[o->i])
			break ;
		o->m = ft_strjoin_2(o->m, o->line[o->i]);
		free(o->line[o->i]);
		o->i++;
	}
	free(o->line[o->i]);
	o->map = ft_split(o->m, '\n');
	while (o->map[o->nbstr])
		o->nbstr++;
	o->nbstr--;
	if (o->nbstr != o->i)
		ft_error("Map not valid\n");
}

int	main(int ac, char **av)
{
	t_data	o;

	if (ac != 2)
		ft_error("Map file not exist\n");
	o.len = ft_strlen(av[1]) - 4;
	if (strncmp(&av[1][o.len],".ber",4))
		ft_error("wrong file\n");
	o.fd = open(av[1], O_RDONLY, 0666);
	if (o.fd == -1)
		exit(1);
	read_from_file(&o);
	printf("Before\n\n");
	print_map(&o);
	// mlx_window(&o);
	parsing(&o);
	return (0);
}
