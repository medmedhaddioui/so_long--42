/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:51:52 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/04/22 14:43:59 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	dup_characters_map_check(t_data *o)
{
	int	player_count;
	int	exit_count;

	player_count = 0;
	exit_count = 0;
	o->i = 0;
	o->j = 0;
	while (o->map[o->i])
	{
		o->j = 0;
		while (o->map[o->i][o->j])
		{
			if (o->map[o->i][o->j] == 'P')
				player_count++;
			else if (o->map[o->i][o->j] == 'E')
				exit_count++;
			o->j++;
		}
		o->i++;
	}
	if (exit_count != 1 || player_count != 1)
		ft_error("Error map must contain 1 exit, and 1 starting position\n",
			o->map);
}

void	characters_map_check(t_data *o)
{
	int	key;
	int	wall;

	o->i = 0;
	key = 0;
	wall = 0;
	while (o->map[o->i])
	{
		o->j = 0;
		while (o->map[o->i][o->j])
		{
			if (o->map[o->i][o->j] != '1' && o->map[o->i][o->j] != '0'
				&& o->map[o->i][o->j] != 'E' && o->map[o->i][o->j] != 'P'
				&& o->map[o->i][o->j] != 'C')
				ft_error("Error character not valid\n", o->map);
			if (o->map[o->i][o->j] == '1')
				wall = 1;
			else if (o->map[o->i][o->j] == 'C')
				key = 1;
			o->j++;
		}
		o->i++;
	}
	if (wall != 1 || key != 1)
		ft_error("Error components missing\n", o->map);
}

void	rectangular_map_check(t_data *o)
{
	o->i = 0;
	o->width = ft_strlen(o->map[o->i]);
	while (o->i < o->nbstr)
	{
		if (o->width != ft_strlen(o->map[o->i]))
			break ;
		o->i++;
	}
	if (o->width != ft_strlen(o->map[o->i]))
		ft_error("Error Map not Rectangular\n", o->map);
}

void	surrounded_map_check(t_data *o)
{
	o->i = 0;
	while (o->map[0][o->i] && o->map[o->nbstr][o->i])
	{
		if (o->map[0][o->i] != '1' || o->map[o->nbstr][o->i] != '1')
			ft_error("Error Map not closed\n", o->map);
		o->i++;
	}
	o->height = 1;
	while (o->height <= o->nbstr - 1)
	{
		if (o->map[o->height][0] != '1' || o->map[o->height][o->width
			- 1] != '1')
			ft_error("Error Map not closed\n", o->map);
		o->height++;
	}
}

void	parsing(t_data *o)
{
	t_pos	v;

	characters_map_check(o);
	dup_characters_map_check(o);
	rectangular_map_check(o);
	surrounded_map_check(o);
	get_xy(o, &v);
	map_copy(o);
	check_valid_path(o, &v);
}
