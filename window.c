/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:15:44 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/04/19 13:57:54 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void put_image(t_var *imgs, int x,int y, char *s)
{
    x *= 50;
    y *= 50;
	imgs->relative_path = s;
    imgs->img =  mlx_xpm_file_to_image(imgs->mlx, imgs->relative_path, 
    &imgs->img_width, &imgs->img_height);
    mlx_put_image_to_window(imgs->mlx, imgs->mlx_win, imgs->img, y, x);
}
void create_window(t_var *imgs,t_data *o)
{
    o->x = 0;
	imgs->mlx = mlx_init();
	imgs->mlx_win = mlx_new_window(imgs->mlx, 1700, 300, "Lo3ba");
    while (o->map[o->x])
    {
        o->y = 0;
        while (o->map[o->x][o->y])
        {
            if (o->map[o->x][o->y] == '1')
                put_image(imgs, o->x, o->y, "./images/wall.xpm");
            if (o->map[o->x][o->y] != '1')
                put_image(imgs, o->x, o->y, "./images/floor.xpm");
            if (o->map[o->x][o->y] == 'P')
                put_image(imgs, o->x, o->y, "./images/player.xpm");
            // if (o->map[o->x][o->y] == 'C')
            //     gem_image(imgs,o->x,o->y, "./images/gem.xpm");
            // if (o->map[o->x][o->y] == 'E')
            //     exit_image(imgs,o->x,o->y, "./images/exit.xpm");
            o->y++;
        }
        o->x++;
    }
    mlx_loop(imgs->mlx);
}

