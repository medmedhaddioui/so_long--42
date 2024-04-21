/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:15:44 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/04/21 17:51:59 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_image(t_var *imgs, int y, int x, char *s)
{
	x *= 50;
	y *= 50;
	imgs->relative_path = s;
	imgs->img = mlx_xpm_file_to_image(imgs->mlx, imgs->relative_path,
			&imgs->img_width, &imgs->img_height);
	mlx_put_image_to_window(imgs->mlx, imgs->mlx_win, imgs->img, x, y);
}
void	find_right_image(t_var *imgs, t_data *o)
{
	o->y = 0;
	while (o->map[o->y])
	{
		o->x = 0;
		while (o->map[o->y][o->x])
		{
			if (o->map[o->y][o->x] == '1')
				put_image(imgs, o->y, o->x, "./images/wall.xpm");
			if (o->map[o->y][o->x] != '1')
				put_image(imgs, o->y, o->x, "./images/floor.xpm");
			if (o->map[o->y][o->x] == 'P')
				put_image(imgs, o->y, o->x, "./images/player.xpm");
			if (o->map[o->y][o->x] == 'C')
				put_image(imgs, o->y, o->x, "./images/coin.xpm");
			if (o->map[o->y][o->x] == 'E')
				put_image(imgs, o->y, o->x, "./images/exit.xpm");
			o->x++;
		}
		o->y++;
	}
}

int	key_hook(int key_hook, t_var *imgs)
{
	t_pos v;
	if (key_hook == D)
		right_key(imgs, &v);
	else if (key_hook == A)
		left_key(imgs, &v);
	else if (key_hook == W)
		up_key(imgs, &v);
	else if (key_hook == S)
		down_key(imgs, &v);
	else if(key_hook == ESC)
		exit(1);
	return (0);
}
void	create_window(t_data *o)
{
	t_var imgs;
	imgs.map2 = o->map;
	o->height = o->nbstr + 1;
	o->width = ft_strlen(o->map[0]);
	o->height *= 50;
	o->width *= 50;
	imgs.mlx = mlx_init();
	imgs.mlx_win = mlx_new_window(imgs.mlx, o->width, o->height, "Lo3ba");
	find_right_image(&imgs, o);
	mlx_key_hook(imgs.mlx_win, key_hook, &imgs);
	mlx_loop(imgs.mlx);
}
