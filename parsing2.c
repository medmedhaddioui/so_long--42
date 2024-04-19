/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:52:02 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/04/18 13:47:56 by mel-hadd         ###   ########.fr       */
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
		|| o->map_fill[y][x] == 'V')
		return ;
	else
		o->map_fill[y][x] = 'V';
	flood_fill(o, x, y - 1);
	flood_fill(o, x, y + 1);
	flood_fill(o, x - 1, y);
	flood_fill(o, x + 1, y);
}
void	get_player_index(t_data *o)
{
	o->x = 0;
	o->y = 0;
	while (o->map[o->y])
	{
		if (o->map[o->y][o->x] == '\0')
		{
			o->x = 0;
			o->y++;
		}
		else if (o->map[o->y][o->x] == 'P')
			break ;
		else
			o->x++;
	}
}
void	get_exit_index(t_data *o)
{
	o->x = 0;
	o->y = 0;
	while (o->map[o->y])
	{
		if (o->map[o->y][o->x] == '\0')
		{
			o->x = 0;
			o->y++;
		}
		else if (o->map[o->y][o->x] == 'E')
			break ;
		else
			o->x++;
	}
}

void	check_valid_path(t_data *o)
{
	flood_fill(o, o->x, o->y);
	get_exit_index(o);
	if (o->map_fill[o->y][o->x] != 'V')
		ft_error("Error Path not valid");
}
