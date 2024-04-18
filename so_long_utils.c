/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hadd <mel-hadd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:17:52 by mel-hadd          #+#    #+#             */
/*   Updated: 2024/04/18 11:55:00 by mel-hadd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *s)
{
	ft_putstr_fd(s, 2);
	exit(1);
}
void	get_index_player(t_data *o)
{
	o->x = 0;
	o->y = 0;
	while (o->map[o->y])
	{
		if (o->map[o->y][o->x] == '\0')
		{
			o->x = 0;
			o->y++;
		}
		else if (o->map[o->y][o->x] == 'P')
			break ;
		else
			o->x++;
	}
}
void	map_copy(t_data *o)
{
	int	i;
	int	lines;

	i = 0;
	lines = 0;
	while (o->map[++lines])
		;
	o->map_fill = malloc(sizeof(char *) * (lines + 1));
	if (!o->map_fill)
		return ;
	while (i < lines)
	{
		o->map_fill[i] = ft_alloc_str (o, i);
		i++;
	}
	o->map_fill[lines] = NULL;
}
char	* ft_alloc_str (t_data *o, int i)
{
	char	*str;
	int		j;
	int		len;

	j = 0;
	len = ft_strlen(o->map[0]);
	str = malloc(sizeof(char) + len + 1);
	if (!str)
		return (NULL);
	while (j < len)
	{
		str[j] = o->map[i][j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

void	print_map(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		printf("%s\n",s[i]);
		i++;
	}
}
