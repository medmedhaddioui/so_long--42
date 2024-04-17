/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:52:02 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/04/17 16:14:30 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(char **map_fill, int x, int y)
{
    if (x < 0, 
        return ;
    else
        map_fill[y][x] = 'V';
	flood_fill(map_fill, x + 1, y);
	flood_fill(map_fill, x - 1, y);
	flood_fill(map_fill, x, y - 1);
	flood_fill(map_fill, x, y + 1);
    
}

















//  char  old;
//     char new;
//     char old_2;
//     old = '0';
//     old_2 = 'C';
//     new = 'V';