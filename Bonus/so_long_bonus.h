/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:15:45 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/04/21 17:51:29 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

#include "../libft/libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <mlx.h>

#define W 13
#define S 1
#define A 0
#define D 2 
#define ESC 53

typedef struct m_data
{
    int fd;
    char  *line;
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

typedef struct t_posistion
{
    int x_player;
    int y_player;
    int x_exit;
    int y_exit;
    
}t_pos;

typedef struct	s_var
{
    void	*mlx_win;
	void	*mlx;
    void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
    char **map2;
    int coin_nb;
}				t_var;

void rectangular_map_check(t_data *o);
void parsing(t_data *o);
void	ft_error(char *s);
void	flood_fill(t_data *o, int x, int y);
void	check_valid_path(t_data *o ,t_pos *v);
void map_copy(t_data *o);
char	* ft_alloc_str (t_data *o, int i);
void	read_from_file(t_data *o);
void create_window(t_data *o);
void put_image(t_var *imgs, int y,int x, char *s);
void find_right_image(t_var *imgs, t_data *o);
int	key_hook(int key_hook, t_var *imgs);
void	right_key(t_var *imgs , t_pos *v);
void	left_key(t_var *imgs , t_pos *v);
void	up_key(t_var *imgs , t_pos *v);
void	down_key(t_var *imgs , t_pos *v);
void get_player_exit_xy (t_var *imgs, t_pos *v);
void get_xy (t_data *o, t_pos *v);



void print_map (char **s);
#endif