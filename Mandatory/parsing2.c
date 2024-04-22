/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:52:02 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/04/22 15:07:28 by mel-hadd         ###   ########.fr       */
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
		|| o->map_fill[y][x] == 'V' || o->map_fill[y][x] == 'E')
		return ;
	else
		o->map_fill[y][x] = 'V';
	flood_fill(o, x, y - 1);
	flood_fill(o, x, y + 1);
	flood_fill(o, x - 1, y);
	flood_fill(o, x + 1, y);
}

void	get_xy(t_data *o, t_pos *v)
{
	v->i = 0;
	while (o->map[v->i])
	{
		v->j = 0;
		while (o->map[v->i][v->j])
		{
			if (o->map[v->i][v->j] == 'P')
			{
				v->x_player = v->j;
				v->y_player = v->i;
			}
			else if (o->map[v->i][v->j] == 'E')
			{
				v->x_exit = v->j;
				v->y_exit = v->i;
			}
			v->j++;
		}
		v->i++;
	}
}

void	check_valid_path(t_data *o, t_pos *v)
{
	flood_fill(o, v->x_player, v->y_player);
	if (o->map_fill[v->y_exit - 1][v->x_exit] != 'V' && o->map_fill[v->y_exit
		+ 1][v->x_exit] != 'V' && o->map_fill[v->y_exit][v->x_exit + 1] != 'V'
		&& o->map_fill[v->y_exit][v->x_exit - 1] != 'V')
	{
		free_map(o->map_fill);
		ft_error("Error Path not valid", o->map);
	}
	o->y = 0;
	while (o->map_fill[o->y])
	{
		o->x = 0;
		while (o->map_fill[o->y][o->x])
		{
			if (o->map_fill[o->y][o->x] == 'C')
			{
				free_map(o->map_fill);
				ft_error("Error coin cant be collected !\n", o->map);
			}
			o->x++;
		}
		o->y++;
	}
	free_map(o->map_fill);
}

void	map_copy(t_data *o)
{
	int	i;
	int	lines;

	i = 0;
	lines = 0;
	while (o->map[++lines])
		;
	o->map_fill = malloc(sizeof(char *) * (lines + 1));
	if (!o->map_fill)
		return ;
	while (i < lines)
	{
		o->map_fill[i] = ft_alloc_str(o, i);
		if (!o->map_fill[i])
			free_map(o->map_fill);
		i++;
	}
	o->map_fill[lines] = NULL;
}

char	*ft_alloc_str(t_data *o, int i)
{
	char	*str;
	int		j;
	int		len;

	j = 0;
	len = ft_strlen(o->map[0]);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (j < len)
	{
		str[j] = o->map[i][j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
