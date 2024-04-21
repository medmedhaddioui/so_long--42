/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:17:52 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/04/21 15:46:18 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *s, char **map)
{
	free_map(map);
	ft_putstr_fd(s, 2);
	exit(1);
}
void ft_exit(char *s)
{
	ft_putstr_fd(s, 2);
	exit(1);
}
void	read_from_file(t_data *o)
{
	o->i =0;
	o->nbstr = 0;
	o->m = get_next_line(o->fd);
	if (!o->m)
		ft_exit("Map not valid\n");
	while (1)
	{
		o->line = get_next_line(o->fd);
		if (!o->line)
			break ;
		o->m = ft_strjoin_2(o->m, o->line);
		free(o->line);
		o->i++;
	}
	free(o->line);
	o->map = ft_split(o->m, '\n');
	free(o->m);
	while (o->map[o->nbstr])
		o->nbstr++;
	o->nbstr--;
	if (o->nbstr != o->i)
		ft_error("Map not valid\n", o->map);
}

void get_player_exit_xy (t_var *imgs, t_pos *v)
{
	imgs->coin_nb = 0;
    int i = 0;
    int j;
    while (imgs->map2[i])
    {
        j = 0;
        while (imgs->map2[i][j])
        {
			if (imgs->map2[i][j] == 'C')
				imgs->coin_nb++;
            if (imgs->map2[i][j] == 'P')
            {
                v->x_player = j;
                v->y_player = i;
            }
            else if (imgs->map2[i][j] == 'E')
            {
                 v->x_exit = j;
                v->y_exit = i;
            }
            j++;
        }
        i++;
    }
}

void free_map(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}
