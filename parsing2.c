/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:52:02 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/04/18 11:55:54 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_data *o, int x, int y)
{
	int	width;
	int	height;

	width = ft_strlen(o->map_fill[0]) - 1;
	height = o->nbstr;
	if (x < 0 || x > width || y < 0 || y > height || o->map_fill[y][x] == '1'
		|| o->map_fill[y][x] == 'E' || o->map_fill[y][x] == 'V')
		return ;
	else
		o->map_fill[y][x] = 'V';
	flood_fill(o, x, y - 1);
	flood_fill(o, x, y + 1);
	flood_fill(o, x - 1, y);
	flood_fill(o, x + 1, y);
}

void	check_valid_path(t_data *o)
{
	printf("Before\n\n");
	print_map(o->map);
	flood_fill(o, o->x, o->y);
	printf("After\n\n");
	print_map(o->map_fill);
}