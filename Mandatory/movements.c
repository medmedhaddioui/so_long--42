/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:13:35 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/04/21 21:11:22 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	right_key(t_var *imgs, t_pos *v)
{
    get_player_exit_xy(imgs, v);
	if (imgs->coin_nb == 0)
		put_image(imgs, v->y_exit, v->x_exit, "./images/open_exit.xpm");
	if (imgs->map2[v->y_player][v->x_player + 1] != '1' &&
	 imgs->map2[v->y_player][v->x_player + 1] != 'E')
	{
		if (imgs->map2[v->y_player][v->x_player + 1] == 'C')
			imgs->coin_nb--;
		put_image(imgs, v->y_player, v->x_player, "./images/floor.xpm");
		put_image(imgs, v->y_player, v->x_player + 1, "./images/player.xpm");
		imgs->map2[v->y_player][v->x_player + 1] = 'P';
		imgs->map2[v->y_player][v->x_player] = '0';
	}
	if (imgs->coin_nb == 0 && imgs->map2[v->y_player][v->x_player + 1] == 'E')
	{
		ft_putstr_fd("You Won !!" , 1);
		exit(0);
	}
}
void	left_key(t_var *imgs, t_pos *v)
{
    get_player_exit_xy(imgs, v);
	if (imgs->coin_nb == 0)
		put_image(imgs, v->y_exit, v->x_exit, "./images/open_exit.xpm");
	if (imgs->map2[v->y_player][v->x_player - 1] != '1' &&
	 imgs->map2[v->y_player][v->x_player - 1] != 'E')
	{
		if (imgs->map2[v->y_player][v->x_player - 1] == 'C')
			imgs->coin_nb--;
		put_image(imgs, v->y_player, v->x_player, "./images/floor.xpm");
		put_image(imgs, v->y_player, v->x_player - 1, "./images/player_left.xpm");
		imgs->map2[v->y_player][v->x_player - 1] = 'P';
		imgs->map2[v->y_player][v->x_player] = '0';
	}
	if (imgs->coin_nb == 0 && imgs->map2[v->y_player][v->x_player - 1] == 'E')
	{
			ft_putstr_fd("You Won !!", 1);
			exit(0);
	}
}
void	up_key(t_var *imgs, t_pos *v)
{
    get_player_exit_xy(imgs, v);
	if (imgs->coin_nb == 0)
		put_image(imgs, v->y_exit, v->x_exit, "./images/open_exit.xpm");
	if (imgs->map2[v->y_player - 1][v->x_player] != '1' && 
	imgs->map2[v->y_player - 1][v->x_player] != 'E')
	{
		if (imgs->map2[v->y_player - 1][v->x_player] == 'C')
			imgs->coin_nb--;
		put_image(imgs, v->y_player, v->x_player, "./images/floor.xpm");
		put_image(imgs, v->y_player - 1, v->x_player, "./images/player.xpm");
		imgs->map2[v->y_player - 1][v->x_player] = 'P';
		imgs->map2[v->y_player][v->x_player] = '0';
	}
	if (imgs->coin_nb == 0 && imgs->map2[v->y_player -1][v->x_player] == 'E')
	{
		ft_putstr_fd("You Won !!", 1);
		exit(0);
	}
}
void	down_key(t_var *imgs, t_pos *v)
{
    get_player_exit_xy(imgs, v);
	if (imgs->coin_nb == 0)
		put_image(imgs, v->y_exit, v->x_exit, "./images/open_exit.xpm");
	if (imgs->map2[v->y_player + 1][v->x_player] != '1' &&
	imgs->map2[v->y_player + 1][v->x_player] != 'E')
	{
		if (imgs->map2[v->y_player + 1][v->x_player] == 'C')
			imgs->coin_nb--;
		put_image(imgs, v->y_player, v->x_player, "./images/floor.xpm");
		put_image(imgs, v->y_player + 1, v->x_player, "./images/player.xpm");
		imgs->map2[v->y_player + 1][v->x_player] = 'P';
		imgs->map2[v->y_player][v->x_player] = '0';
	}
	if (imgs->coin_nb == 0 && imgs->map2[v->y_player + 1][v->x_player] == 'E')
	{
		ft_putstr_fd("You Won !!" ,1);
		exit(0);
	}
}

