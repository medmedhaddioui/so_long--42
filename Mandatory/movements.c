/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:13:35 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/04/27 12:06:14 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_var *imgs)
{
	ft_printf("%d\n", imgs->count++);
	ft_putstr_fd("You Won !!\n", 1);
	free_map(imgs->map2);
	mlx_destroy_window(imgs->mlx, imgs->mlx_win);
	exit(EXIT_SUCCESS);
}

void	right_key(t_var *imgs, t_pos *v)
{
	get_player_exit_xy(imgs, v);
	if (imgs->coin_nb == 0)
		put_image(imgs, v->y_exit, v->x_exit, "./images/open_exit.xpm");
	if (imgs->map2[v->y_player][v->x_player + 1] != '1'
		&& imgs->map2[v->y_player][v->x_player + 1] != 'E')
		move_player_right(imgs, v->y_player, v->x_player);
	if (imgs->coin_nb == 0 && imgs->map2[v->y_player][v->x_player + 1] == 'E')
		exit_game(imgs);
}

void	left_key(t_var *imgs, t_pos *v)
{
	get_player_exit_xy(imgs, v);
	if (imgs->coin_nb == 0)
		put_image(imgs, v->y_exit, v->x_exit, "./images/open_exit.xpm");
	if (imgs->map2[v->y_player][v->x_player - 1] != '1'
		&& imgs->map2[v->y_player][v->x_player - 1] != 'E')
		move_player_left(imgs, v->y_player, v->x_player);
	if (imgs->coin_nb == 0 && imgs->map2[v->y_player][v->x_player - 1] == 'E')
		exit_game(imgs);
}

void	up_key(t_var *imgs, t_pos *v)
{
	get_player_exit_xy(imgs, v);
	if (imgs->coin_nb == 0)
		put_image(imgs, v->y_exit, v->x_exit, "./images/open_exit.xpm");
	if (imgs->map2[v->y_player - 1][v->x_player] != '1'
		&& imgs->map2[v->y_player - 1][v->x_player] != 'E')
		move_player_up(imgs, v->y_player, v->x_player);
	if (imgs->coin_nb == 0 && imgs->map2[v->y_player - 1][v->x_player] == 'E')
		exit_game(imgs);
}

void	down_key(t_var *imgs, t_pos *v)
{
	get_player_exit_xy(imgs, v);
	if (imgs->coin_nb == 0)
		put_image(imgs, v->y_exit, v->x_exit, "./images/open_exit.xpm");
	if (imgs->map2[v->y_player + 1][v->x_player] != '1'
		&& imgs->map2[v->y_player + 1][v->x_player] != 'E')
		move_player_down(imgs, v->y_player, v->x_player);
	if (imgs->coin_nb == 0 && imgs->map2[v->y_player + 1][v->x_player] == 'E')
		exit_game(imgs);
}
