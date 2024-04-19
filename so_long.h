/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:15:45 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/04/19 13:56:18 by mel-hadd         ###   ########.fr       */
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
    char **map_fill;
    int nbstr;
    size_t width;
    int height;
    int i;
    int j;
    int x;
    int y;
    size_t len;

} t_data;

typedef struct	s_var
{
    void	*mlx_win;
	void	*mlx;
    void	*img;
    
	char	*relative_path;
	int		img_width;
	int		img_height;
}				t_var;

void rectangular_map_check(t_data *o);
void parsing(t_data *o);
void	ft_error(char *s);
void	get_player_index(t_data *o);
void	flood_fill(t_data *o, int x, int y);
void	check_valid_path(t_data *o);
void map_copy(t_data *o);
char	* ft_alloc_str (t_data *o, int i);
void	get_exit_index(t_data *o);
void	read_from_file(t_data *o);
void create_window(t_var *imgs, t_data *o);
void put_image(t_var *imgs, int x,int y, char *s);


void print_map (char **s);
#endif