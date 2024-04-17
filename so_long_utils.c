/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:17:52 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/04/17 15:35:43 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *s)
{
	ft_putstr_fd(s, 2);
	exit(1);
}
void	get_index_player(t_data *o)
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
			break;
		else
			o->x++;
	}
}
void print_map (t_data *o)
{
	int i;
	i = 0;
	while (o->map[i])
	{
		printf("%s\n",o->map[i]);
		i++;
	}
}
