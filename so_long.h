/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:15:45 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/04/17 15:23:36 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_H
# define SO_LONG_H

#include "./libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <mlx.h>

typedef struct m_data
{
    int fd;
    char  *line[100];
    char *m;
    char **map;
    int nbstr;
    size_t width;
    int height;
    int i;
    int j;
    int x;
    int y;
    size_t len;

} t_data;

void rectangular_map_check(t_data *o);
void parsing(t_data *o);
void	ft_error(char *s);
void mlx_window (t_data *o);
void	flood_fill(char **map_fill, int x, int y);



void	get_index_player(t_data *o);
void print_map (t_data *o);

#endif