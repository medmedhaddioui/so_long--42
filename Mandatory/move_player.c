/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:24:06 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/04/27 12:05:58 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player_right(t_var *imgs, int y, int x)
{
	ft_printf("%d\n", imgs->count++);
	if (imgs->map2[y][x] == 'C')
		imgs->coin_nb--;
	put_image(imgs, y, x, "./images/floor.xpm");
	put_image(imgs, y, x + 1, "./images/player.xpm");
	imgs->map2[y][x + 1] = 'P';
	imgs->map2[y][x] = '0';
}

void	move_player_left(t_var *imgs, int y, int x)
{
	ft_printf("%d\n", imgs->count++);
	if (imgs->map2[y][x] == 'C')
		imgs->coin_nb--;
	put_image(imgs, y, x, "./images/floor.xpm");
	put_image(imgs, y, x - 1, "./images/player.xpm");
	imgs->map2[y][x - 1] = 'P';
	imgs->map2[y][x] = '0';
}

void	move_player_up(t_var *imgs, int y, int x)
{
	ft_printf("%d\n", imgs->count++);
	if (imgs->map2[y][x] == 'C')
		imgs->coin_nb--;
	put_image(imgs, y, x, "./images/floor.xpm");
	put_image(imgs, y - 1, x, "./images/player.xpm");
	imgs->map2[y - 1][x] = 'P';
	imgs->map2[y][x] = '0';
}

void	move_player_down(t_var *imgs, int y, int x)
{
	ft_printf("%d\n", imgs->count++);
	if (imgs->map2[y][x] == 'C')
		imgs->coin_nb--;
	put_image(imgs, y, x, "./images/floor.xpm");
	put_image(imgs, y + 1, x, "./images/player.xpm");
	imgs->map2[y + 1][x] = 'P';
	imgs->map2[y][x] = '0';
}
