/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 21:15:45 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/04/22 21:23:05 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>

# define W 13
# define S 1
# define A 0
# define D 2
# define ESC 53
# define MAX_WIDTH 2550
# define MAX_HEIGHT 1400


typedef struct m_data
{
	int		fd;
	char	*line;
	char	*m;
	char	**map;
	char	**map_fill;
	int		nbstr;
	size_t	width;
	int		height;
	int		i;
	int		j;
	int		x;
	int		y;
	size_t	len;

}			t_data;

typedef struct t_posistion
{
	int		x_player;
	int		y_player;
	int		x_exit;
	int		y_exit;
	int		i;
	int		j;

}			t_pos;

typedef struct s_var
{
	void	*mlx_win;
	void	*mlx;
	void	*img;
	char	*path;
	int		img_width;
	int		img_height;
	char	**map2;
	int		coin_nb;
	int		count;
}			t_var;

void		rectangular_map_check(t_data *o);
void		parsing(t_data *o);
void		ft_error(char *s, char **map);
void		ft_exit(char *s);
void		flood_fill(t_data *o, int x, int y);
void		check_valid_path(t_data *o, t_pos *v);
void		map_copy(t_data *o);
char		*ft_alloc_str(t_data *o, int i);
void		read_from_file(t_data *o);
void		graphical_map(t_data *o);
void		put_image(t_var *imgs, int y, int x, char *s);
void		find_right_image(t_var *imgs, t_data *o);
int			key_hook(int key_hook, t_var *imgs);
void		right_key(t_var *imgs, t_pos *v);
void		left_key(t_var *imgs, t_pos *v);
void		up_key(t_var *imgs, t_pos *v);
void		down_key(t_var *imgs, t_pos *v);
void		get_player_exit_xy(t_var *imgs, t_pos *v);
void		get_xy(t_data *o, t_pos *v);
void		free_map(char **s);

#endif
